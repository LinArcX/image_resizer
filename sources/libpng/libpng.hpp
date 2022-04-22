#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include <png.h>

class InputOutput {

public:
  void read(char *filename);
  void write(char *filename);
  void process();

private:
  int width;
  int height;
  png_byte color_type;
  png_byte bit_depth;
  png_bytep *row_pointers = NULL;
};

#endif
