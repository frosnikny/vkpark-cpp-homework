#ifndef CPP_HW1_ARG_UTILS_HPP
#define CPP_HW1_ARG_UTILS_HPP

#include <limits>
#include <map>
#include <stdexcept>
#include <string>

#include "./errors.hpp"

std::map<std::string, std::string> take_args(int argc, char* argv[]);

std::map<std::string, std::string> handle_args(int argc, char* argv[],
                                               int& max_duration);

#endif  // CPP_HW1_ARG_UTILS_HPP
