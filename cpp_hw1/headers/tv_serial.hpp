#ifndef CPP_HW1_HEADERS_TV_SERIAL_HPP
#define CPP_HW1_HEADERS_TV_SERIAL_HPP

#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

struct TVSerial {
  std::string title{};
  std::string ru_title{};
  std::vector<std::string> episode_numbers{};
  double avg_rating{};
  int average_episode_duration{};
};

// Contains information about TVSerials from files
class SerialsCollection {
  std::unordered_map<std::string, TVSerial> serials_{};
  std::unordered_map<std::string, int> episode_durations_{};

 public:
  std::unordered_map<std::string, TVSerial>& getSerials() { return serials_; }

  const std::unordered_map<std::string, TVSerial>& getSerials() const {
    return serials_;
  }

  std::unordered_map<std::string, int>& getEpisodeDurations() {
    return episode_durations_;
  }

  const std::unordered_map<std::string, int>& getEpisodeDurations() const {
    return episode_durations_;
  }
};

typedef std::pair<std::string, TVSerial> TVSerialPair;

#endif  // CPP_HW1_HEADERS_TV_SERIAL_HPP
