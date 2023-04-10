#include "operations/Cat.hpp"

Cat::Cat(const std::string& file_name) {
  std::ifstream file(file_name);
  if (!file.is_open()) {
    throw std::invalid_argument("Invalid file path passed");
  }
  std::string line;
  while (getline(file, line)) {
    own_data_.push(line);
  }
  file.close();
}

void Cat::processLine(const std::string& input_str) {
  input_data_.push(input_str);
}

void Cat::handleEndOfInput() {
  if (next_operation_ == nullptr) {
    while (!input_data_.empty()) {
      std::cout << input_data_.front() << std::endl;
      input_data_.pop();
    }
    while (!own_data_.empty()) {
      std::cout << own_data_.front() << std::endl;
      own_data_.pop();
    }
    return;
  }
  while (!input_data_.empty()) {
    next_operation_->processLine(input_data_.front());
    input_data_.pop();
  }
  while (!own_data_.empty()) {
    next_operation_->processLine(own_data_.front());
    own_data_.pop();
  }

  next_operation_->handleEndOfInput();
}

void Cat::setNextOperation(std::unique_ptr<IOperation> next_operation) {
  next_operation_ = std::move(next_operation);
}
