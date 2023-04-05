#ifndef CPP_HW2_I_OPERATION_HPP
#define CPP_HW2_I_OPERATION_HPP

#include <memory>
#include <string>

class IOperation {
 public:
  virtual void processLine(const std::string&) = 0;
  virtual void handleEndOfInput() = 0;
  virtual void setNextOperation(std::unique_ptr<IOperation>) = 0;
  virtual ~IOperation() = default;
};

#endif  // CPP_HW2_I_OPERATION_HPP
