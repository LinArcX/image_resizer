#ifndef INPUT_OUTPUT_HPP
#define INPUT_OUTPUT_HPP

#include <string>
#include <vector>

class InputOutput
{
public:
  // , std::vector<unsigned char>& data
  // , const std::vector<unsigned char>& data,
  static bool readBinaryFile(const std::string& fileName);
  static bool writeBinaryFile(const std::string& fileName, unsigned size=0);
  static char* data;

private:
};

#endif
