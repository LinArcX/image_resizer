#ifndef PROFILE_HPP
#define PROFILER_HPP

#include <ctime>
#include <string>
#include <iostream>
#include <unordered_map>

class Profiler
{
public:

  static void start(const std::string& name)
  {
    m_clocks[name] = clock();
  }

  static void stop(const std::string& name)
  {
    const auto& clock_curr = m_clocks.find(name);
    auto ms = float(clock() - clock_curr->second) / CLOCKS_PER_SEC * 1000.0f;
    std::cout << "Elapsed time " << name << ": " << ms << "[ms]" << std::endl;
    m_clocks.erase(clock_curr);
  }

  static clock_t start()
  {
    return clock();
  }

  static unsigned long stop(clock_t start)
  {
    auto ms = float(clock() - start) / CLOCKS_PER_SEC * 1000.0f;
    return ms;
  }

private:

    static std::unordered_map<std::string, clock_t> m_clocks;
};

#endif
