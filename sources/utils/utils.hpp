#pragma once

#include <algorithm>
#include <string>
#include <vector>

class Utils
{
public:

  template<typename T>
  static T minimum(T a, T b)
  {
      #ifdef min
		return min(a, b);
      #else
          return std::min(a, b);
      #endif
  }

  template<typename T>
  static T maximum(T a, T b)
  {
      #ifdef max
		return max(a, b);
      #else
          return std::max(a, b);
      #endif
  }
};
