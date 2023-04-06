#include "task.hpp"

void runTask(const std::string& arguments_str) {
  ConveyorParser parser;
  parser.parse(arguments_str);
  parser.process();
}
