#ifndef CPP_HW1_HEADERS_TV_SERIAL_HPP
#define CPP_HW1_HEADERS_TV_SERIAL_HPP

#include <string>
#include <utility>
#include <vector>

struct TVSerial {
  std::string title{};
  std::string ru_title{};
  std::vector<std::string> episode_numbers{};
  double avg_rating{};
  int average_episode_duration{};
};

typedef std::pair<std::string, TVSerial> TVSerialPair;

#endif  // CPP_HW1_HEADERS_TV_SERIAL_HPP
