#ifndef CPP_HW2_CUT_HPP
#define CPP_HW2_CUT_HPP

#include <iostream>
#include <memory>
#include <queue>
#include <sstream>
#include <string>

#include "IOperation.hpp"

class Cut : public IOperation {
 public:
  explicit Cut(size_t N) : word_number_(N) {}
  void processLine(const std::string& input_str) override;
  void handleEndOfInput() override;
  void setNextOperation(std::unique_ptr<IOperation> next_operation) override;

 private:
  size_t word_number_;
  std::queue<std::string> input_convert_data_;
  std::unique_ptr<IOperation> next_operation_{nullptr};
};

#endif  // CPP_HW2_CUT_HPP
