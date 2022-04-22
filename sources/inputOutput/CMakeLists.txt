# please change these absolute path according to your system
include("/mnt/D/workspace/c++/cpp/projects/active/image_resizer/dependencies/lib/libpng/libpng16.cmake")
set(LIBPNG_INCLUDE_DIR "/mnt/D/workspace/c++/cpp/projects/active/image_resizer/dependencies/include")

add_library(
  inputOutput
  inputOutput.hpp
  inputOutput.cpp)

target_link_libraries(inputOutput png_static)
target_include_directories(inputOutput PUBLIC ${LIBPNG_INCLUDE_DIR})
