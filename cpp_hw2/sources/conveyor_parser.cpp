#include "conveyor_parser.hpp"

void ConveyorParser::parse(std::string arguments_str) {
  std::stack<std::pair<std::string, std::string>> arguments;
  std::string command_str;
  std::string delimiter(" | ");
  size_t delimiter_pos = 0;
  while ((delimiter_pos = arguments_str.find(delimiter)) != std::string::npos) {
    command_str = arguments_str.substr(0, delimiter_pos);
    addOperation(command_str);
    arguments_str.erase(0, delimiter_pos + delimiter.length());
  }
  addOperation(arguments_str);
}

void ConveyorParser::process() {
  std::unique_ptr<IOperation> previous_operation{nullptr};
  while (!operations_.empty()) {
    std::unique_ptr<IOperation> operation = std::move(operations_.top());
    operations_.pop();
    operation->setNextOperation(std::move(previous_operation));
    previous_operation = std::move(operation);
  }
  previous_operation->handleEndOfInput();
}

std::pair<std::string, std::string> ConveyorParser::separateSpaces(
    const std::string& str) {
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

void ConveyorParser::addOperation(const std::string& command_str) {
  std::pair<std::string, std::string> command_item =
      separateSpaces(command_str);
  if (command_item.first == "cat") {
    std::unique_ptr<Cat> cat = std::make_unique<Cat>(command_item.second);
    operations_.push(std::move(cat));
  } else if (command_item.first == "echo") {
    std::unique_ptr<Echo> echo = std::make_unique<Echo>(command_item.second);
    operations_.push(std::move(echo));
  } else if (command_item.first == "cut") {
    int n = std::stoi(command_item.second);
    std::unique_ptr<Cut> cut = std::make_unique<Cut>(n);
    operations_.push(std::move(cut));
  } else {
    throw std::invalid_argument("Invalid command passed");
  }
}
