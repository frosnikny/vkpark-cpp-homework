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

#include <iostream>

void calculateDuration(SerialsCollection& collection, int max_duration);

bool compareRatings(const TVSerialPair& a, const TVSerialPair& b);

std::vector<TVSerialPair> takeBestRatings(const SerialsCollection& collection,
                                          int required_number);

void runTask(std::ostream& out, const std::string& basics_filename,
             const std::string& episodes_filename,
             const std::string& ratings_filename,
             const std::string& akas_filename, int max_duration,
             int required_best_number);

#endif  // CPP_HW1_HEADERS_EXERCISE_HPP
