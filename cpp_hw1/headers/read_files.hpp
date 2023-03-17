#ifndef CPP_HW1_HEADERS_READ_FILES_HPP
#define CPP_HW1_HEADERS_READ_FILES_HPP

#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "./tv_serial.hpp"

class Parser {
 public:
  // function for reading episodes from title.episode.tsv
  static void readEpisodes(
      const std::string& filename,
      std::unordered_map<std::string, TVSerial>& serials,
      std::unordered_map<std::string, int>& episode_durations);

  // function for reading info from title.basics.tsv
  static void readSerials(
      const std::string& filename,
      std::unordered_map<std::string, TVSerial>& serials,
      std::unordered_map<std::string, int>& episode_durations);

  // function for reading ratings from title.ratings.tsv
  static void readRatings(const std::string& filename,
                          std::unordered_map<std::string, TVSerial>& serials);

  // function for reading episodes from title.akas.tsv
  static void readAkas(const std::string& filename,
                       std::vector<TVSerialPair>& serials);
};

#endif  // CPP_HW1_HEADERS_READ_FILES_HPP
