# please change these absolute path according to your system
#include("/mnt/D/workspace/c++/cpp/projects/active/image_resizer/dependencies/lib/libpng/libpng16.cmake")
#set(LIBPNG_INCLUDE_DIR "/mnt/D/workspace/c++/cpp/projects/active/image_resizer/dependencies/include")

add_library(
  image
  Image.hpp
  Image.cpp
  Png.hpp
  Png.cpp)

#target_link_libraries(image png_static)
target_include_directories(image PUBLIC
  ${LIBPNG_INCLUDE_DIR}
  input_output)

target_link_libraries(image PUBLIC
  input_output)
