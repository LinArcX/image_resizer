#include <iostream>
#include <stdlib.h>
#include <cstdlib>

#include "resizer/resizer.hpp"

auto ratio(1.0f);
auto quality(100);
auto algo("bicubic");

std::string input;
std::string output;
std::unordered_map<std::string, float> profiler;

int handle_arguments(int argc, char *argv[])
{
  if (1 == argc)
  {
    std::cout << "Example usage: resizer -output <output_file> -input <input_file> -ratio 0.8 -quality 90 -algo bicubic" << std::endl;
    return EXIT_FAILURE;
  }

  for (int i=1; i < argc; i++)
  {
      std::string arg = argv[i];

      if (arg == "-output")
      {
          output = argv[i+1];
          i++;
          continue;
      }

      if (arg == "-input")
      {
          input = argv[i+1];
          i++;
          continue;
      }

      if (arg == "-ratio")
      {
          ratio = atof(argv[i+1]);
          i++;
          continue;
      }

      if (arg == "-quality")
      {
          quality = atoi(argv[i+1]);
          i++;
          continue;
      }

      if (arg == "-algo")
      {
          algo = argv[i+1];
          i++;
          continue;
      }
  }
  return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
  if(EXIT_FAILURE == handle_arguments(argc, argv))
    return EXIT_FAILURE;

  if(EXIT_FAILURE == Resizer::resize(input, output, ratio, quality, algo, profiler))
    return EXIT_FAILURE;

  return EXIT_SUCCESS;
}
