#include "task.hpp"

void runTask(std::stack<std::pair<std::string, std::string>> arguments) {
  std::unique_ptr<IOperation> previous_operation{nullptr};
  while (!arguments.empty()) {
    std::pair<std::string, std::string> command_item = arguments.top();
    arguments.pop();
    if (command_item.first == "cat") {
      std::unique_ptr<Cat> cat = std::make_unique<Cat>(command_item.second);
      cat->setNextOperation(std::move(previous_operation));
      previous_operation = std::move(cat);
    } else if (command_item.first == "echo") {
      std::unique_ptr<Echo> echo = std::make_unique<Echo>(command_item.second);
      echo->setNextOperation(std::move(previous_operation));
      previous_operation = std::move(echo);
    } else if (command_item.first == "cut") {
      int n = std::stoi(command_item.second);
      std::unique_ptr<Cut> cut = std::make_unique<Cut>(n);
      cut->setNextOperation(std::move(previous_operation));
      previous_operation = std::move(cut);
    } else {
      throw std::invalid_argument("Invalid command passed");
    }
  }
  previous_operation->handleEndOfInput();
}
