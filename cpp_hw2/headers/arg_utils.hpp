#ifndef CPP_HW2_ARG_UTILS_HPP
#define CPP_HW2_ARG_UTILS_HPP

#include <stack>
#include <stdexcept>
#include <string>
#include <utility>

std::pair<std::string, std::string> separate_spaces(const std::string&);

std::stack<std::pair<std::string, std::string>> take_args(const std::string&);

#endif  // CPP_HW2_ARG_UTILS_HPP
