#include "resizer.hpp"

#include <cstdlib>
#include <iostream>

#include "../opencl/openclManager.hpp"
#include "../opencl/resize_kernel.h"
#include "../opencl/profiler.hpp"
#include "../image/PNGImage.hpp"

int Resizer::resize(const std::string& input,
                     const std::string& output,
                     float ratio,
                     int quality,
                     const std::string& options,
                     std::unordered_map<std::string, float>& profiler)
{
  auto outFile = output;
  std::string samplingAlgo;

  // check for re-sampling algorithm
  for (const auto& e : entries)
  {
    if (e.find(options) != std::string::npos)
    {
      samplingAlgo = e;
      break;
    }
  }

  if (samplingAlgo.empty())
  {
      std::cerr << "Invalid resampling method, available methods: [nn, linear, bicubic]" << std::endl;
      return EXIT_FAILURE;
  }

  openClManager manager;
  if (!manager.createContext(openClManager::GPU))
  {
      return EXIT_FAILURE;
  }

  if (!manager.addKernelProgram(resizeKernel))
  {
      std::cerr << "Error building kernel." << std::endl;
      return EXIT_FAILURE;
  }

  PNGImage imageIn;
  PNGImage imageOut;

  auto readProf = 0;
  auto writeProf = 0;
  auto resizeProf = 0;

  profiler["op"] += 1;

  auto r = Profiler::start();
  if (imageIn.load(input))
  {
      readProf += Profiler::stop(r);

      auto res = Profiler::start();
      manager.resizeImage(imageIn, imageOut, ratio, samplingAlgo);
      resizeProf += Profiler::stop(res);

      auto w = Profiler::start();
      imageOut.save(outFile, quality);
      writeProf += Profiler::stop(w);
  }

  profiler["read"] += readProf;
  profiler["write"] += writeProf;
  profiler["resize"] += resizeProf;

  return EXIT_SUCCESS;
}
