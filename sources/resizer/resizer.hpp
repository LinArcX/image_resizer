#ifndef RESIZER_HPP
#define RESIZER_HPP

#include <string>
#include <vector>
#include <unordered_map>

class Resizer
{
public:

  /**
   *
   * @param inputDir input directory of images to be resized
   * @param outputDir output directory where the images will be resized
   * @param ratio ratio of resizing, eg. 0.5 will result in 50% smaller image
   * @param quality quality of output JPEG <1, 100>
   * @param options resizing algorithm
   */
  static int resize(const std::string& input,
                       const std::string& output,
                       float ratio,
                       int quality,
                       const std::string& options,
                       std::unordered_map<std::string, float>& profiler);
};

#endif
