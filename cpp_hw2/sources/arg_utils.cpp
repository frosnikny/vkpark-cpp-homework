#include "arg_utils.hpp"

std::pair<std::string, std::string> separate_spaces(const std::string& str) {
  std::size_t space_pos = str.find(' ');
  if (space_pos == std::string::npos) {
    throw std::invalid_argument("The command was passed without an argument");
  }
  std::string command = str.substr(0, space_pos);
  std::string argument = str.substr(space_pos + 1);
  if (argument.empty()) {
    throw std::invalid_argument("The command was passed without an argument");
  }
  return std::make_pair(command, argument);
}

std::stack<std::pair<std::string, std::string>> take_args(
    const std::string& argv) {
  std::stack<std::pair<std::string, std::string>> arguments;
  std::string arguments_str(argv);
  std::string command_str;
  std::string command;
  std::string argument;
  std::string delimiter(" | ");
  size_t delimiter_pos = 0;
  while ((delimiter_pos = arguments_str.find(delimiter)) != std::string::npos) {
    command_str = arguments_str.substr(0, delimiter_pos);

    arguments.push(separate_spaces(command_str));

    arguments_str.erase(0, delimiter_pos + delimiter.length());
  }
  arguments.push(separate_spaces(arguments_str));

  return arguments;
}
