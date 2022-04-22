FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(OPENCL REQUIRED OpenCL)

add_library(
  opencl
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
