add_library(
  input_output
  InputOutput.hpp
  InputOutput.cpp)

target_include_directories(input_output PUBLIC
  ${OPENCL_INCLUDE_DIRS})
