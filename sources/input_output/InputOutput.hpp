#ifndef INPUT_OUTPUT_HPP
#define INPUT_OUTPUT_HPP

#include <string>
#include <vector>

class InputOutput
{
public:
  static bool readBinaryFile(const std::string& fileName, std::vector<unsigned char>& data);
  static bool writeBinaryFile(const std::string& fileName, const std::vector<unsigned char>& data, unsigned size=0);
};

#endif
