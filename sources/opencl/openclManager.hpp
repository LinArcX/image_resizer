#ifndef OPENCL_MANAGER_HPP
#define OPENCL_MANAGER_HPP

#include <string>
#include "opencl.hpp"

class Image;
class openClManager
{

public:
  enum DeviceType
  {
    CPU = CL_DEVICE_TYPE_CPU,
    GPU = CL_DEVICE_TYPE_GPU
  };

  bool createContext(DeviceType type);
  bool addKernelProgram(const std::string& kernel);
  void resizeImage(const Image& in, Image& out, float ratio, const std::string& programEntry);

protected:
  void setupPlatform(DeviceType type);
  static char *getCLErrorString(cl_int err);
	cl::ImageFormat getImageFormat(const Image&) const;

	cl::Platform      m_platform;
	cl::Device        m_device;
  cl::Context       m_context;
  cl::Program       m_program;
  cl::CommandQueue  m_queue;
	static const std::string preferredDeviceVendors[];
};

#endif
