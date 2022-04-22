#include <stdlib.h>
#include "inputOutput/inputOutput.hpp"

int main(int argc, char *argv[]) {
  if(argc != 3)
    abort();

  InputOutput input_output;
  input_output.read(argv[1]);
  input_output.process();
  input_output.write(argv[2]);

  return 0;
}
