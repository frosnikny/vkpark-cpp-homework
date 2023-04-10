#ifndef CPP_HW2_CAT_HPP
#define CPP_HW2_CAT_HPP

#include <fstream>
#include <iostream>
#include <memory>
#include <queue>
#include <stdexcept>
#include <string>

#include "IOperation.hpp"

class Cat : public IOperation {
 public:
  explicit Cat(const std::string& file_name);
  void processLine(const std::string& input_str) override;
  void handleEndOfInput() override;
  void setNextOperation(std::unique_ptr<IOperation> next_operation) override;

 private:
  std::queue<std::string> own_data_;
  std::queue<std::string> input_data_;
  std::unique_ptr<IOperation> next_operation_{nullptr};
};

#endif  // CPP_HW2_CAT_HPP
