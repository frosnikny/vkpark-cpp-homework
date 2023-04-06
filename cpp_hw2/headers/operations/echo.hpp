#ifndef CPP_HW2_ECHO_HPP
#define CPP_HW2_ECHO_HPP

#include <iostream>
#include <memory>
#include <string>
#include <utility>

#include "i_operation.hpp"

class Echo : public IOperation {
 public:
  explicit Echo(std::string str) : own_data_(std::move(str)) {}
  void processLine(const std::string& input_str) override {}
  void handleEndOfInput() override;
  void setNextOperation(std::unique_ptr<IOperation> next_operation) override;

 private:
  std::string own_data_;
  std::unique_ptr<IOperation> next_operation_{nullptr};
};

#endif  // CPP_HW2_ECHO_HPP
