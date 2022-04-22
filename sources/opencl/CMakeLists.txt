FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(OPENCL REQUIRED OpenCL)

#find_package(OpenCL REQUIRED)
#include_directories(${OPENCL_INCLUDE_DIR})

add_library(
  opencl
  opencl.hpp
  profiler.hpp
  resize_kernel.h
  openclManager.hpp
  openclManager.cpp)

target_include_directories(opencl PUBLIC
  ${OPENCL_INCLUDE_DIRS}
  "${CMAKE_CURRENT_SOURCE_DIR}"
  image
  utils)

target_link_libraries(opencl PUBLIC
  ${OPENCL_LIBRARIES}
  image
  utils)
