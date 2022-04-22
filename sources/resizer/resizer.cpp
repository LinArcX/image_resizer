#include "resizer.hpp"

#include <cstdlib>
#include <iostream>

#include <CL/cl.h>

#include "../opencl/openclManager.hpp"
#include "../opencl/resize_kernel.h"
#include "../image/Png.hpp"

int Resizer::resize(const std::string& input,
                     const std::string& output,
                     float ratio,
                     int quality,
                     const std::string& options)

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

  Png input_image;
  Png output_image;

  if (input_image.load(input))
  {
      manager.resizeImage(input_image, output_image, ratio, samplingAlgo);
      output_image.save(outFile, quality);
  }

  return EXIT_SUCCESS;
}
