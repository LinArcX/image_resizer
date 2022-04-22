#include <iostream>
#include <stdlib.h>
#include <cstdlib>

#include "resizer/resizer.hpp"
#include "arguments_handler/ArgumentsHandler.hpp"

int main(int argc, char** argv)
{
  ArgumentsHandler argumentHandler;
  if(EXIT_FAILURE == argumentHandler.handle_arguments(argc, argv))
  {
    return EXIT_FAILURE;
  }

  if(EXIT_FAILURE == Resizer::resize(argumentHandler.getInput(),
                                     argumentHandler.getOutput(),
                                     argumentHandler.getRatio(),
                                     argumentHandler.getQuality(),
                                     argumentHandler.getAlgorithm()))
  {
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
