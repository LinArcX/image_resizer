add_library(
  arguments_handler
  ArgumentsHandler.hpp
  ArgumentsHandler.cpp)

target_include_directories(arguments_handler PUBLIC
  "${CMAKE_CURRENT_SOURCE_DIR}")
