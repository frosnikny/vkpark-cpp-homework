#include "../../headers/operations/cut.hpp"

void Cut::processLine(const std::string& input_str) {
  std::string word{};
  size_t word_count = 0;
  std::istringstream str_stream(input_str);
  while (!str_stream.eof()) {
    std::getline(str_stream, word, ' ');
    ++word_count;
    if (word_count == word_number_) {
      input_convert_data_.push(word);
      break;
    }
  }
}

void Cut::handleEndOfInput() {
  if (next_operation_ == nullptr) {
    while (!input_convert_data_.empty()) {
      std::cout << input_convert_data_.front() << std::endl;
      input_convert_data_.pop();
    }
    return;
  }
  while (!input_convert_data_.empty()) {
    next_operation_->processLine(input_convert_data_.front());
    input_convert_data_.pop();
  }

  next_operation_->handleEndOfInput();
}

void Cut::setNextOperation(std::unique_ptr<IOperation> next_operation) {
  next_operation_ = std::move(next_operation);
}
