#include "operations/echo.hpp"

void Echo::handleEndOfInput() {
  if (next_operation_ == nullptr) {
    std::cout << own_data_ << std::endl;
    return;
  }
  next_operation_->processLine(own_data_);

  next_operation_->handleEndOfInput();
}

void Echo::setNextOperation(std::unique_ptr<IOperation> next_operation) {
  next_operation_ = std::move(next_operation);
}
