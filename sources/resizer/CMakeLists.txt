add_library(
  resizer
  resizer.hpp
  resizer.cpp)

target_include_directories(resizer PUBLIC
  "${CMAKE_CURRENT_SOURCE_DIR}"
  opencl
  image)

target_link_libraries(resizer PUBLIC
  opencl
  image)
