#include "ArgumentsHandler.hpp"

int ArgumentsHandler::handle_arguments(int argc, char** argv)
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

    if (arg == "-algorithm")
    {
      algorithm = argv[i+1];
      i++;
      continue;
    }
  }
  return EXIT_SUCCESS;
}
