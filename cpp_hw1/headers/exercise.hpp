#ifndef CPP_HW1_HEADERS_EXERCISE_HPP
#define CPP_HW1_HEADERS_EXERCISE_HPP

#include <fstream>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "./read_files.hpp"
#include "./tv_serial.hpp"

void calculateDuration(std::unordered_map<std::string, TVSerial>& serials,
                       std::unordered_map<std::string, int>& episode_durations,
                       int max_duration);

bool compareRatings(const TVSerialPair& a, const TVSerialPair& b);

void takeBestRatings(
    const std::unordered_map<std::string, TVSerial>& serials,
    std::priority_queue<TVSerialPair, std::vector<TVSerialPair>,
                        decltype(&compareRatings)>& best_serials_pq,
    int required_number);

void runTask(std::ostream& out, const std::string& basics_filename,
             const std::string& episodes_filename,
             const std::string& ratings_filename,
             const std::string& akas_filename, int max_duration,
             int required_best_number);

#endif  // CPP_HW1_HEADERS_EXERCISE_HPP
