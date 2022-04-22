#ifndef RESIZER_HPP
#define RESIZER_HPP

#include <string>
#include <vector>
#include <unordered_map>

class Resizer
{

public:
  static int resize(const std::string& input,
                       const std::string& output,
                       float ratio, // ratio of resizing, eg. 0.5 will result in 50% smaller image
                       int quality,
                       const std::string& options); //resizing algorithm
};
#endif
