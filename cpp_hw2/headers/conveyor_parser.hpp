#ifndef CPP_HW2_CONVEYOR_PARSER_HPP
#define CPP_HW2_CONVEYOR_PARSER_HPP

#include <memory>
#include <stack>
#include <string>
#include <utility>

#include "operations/cat.hpp"
#include "operations/cut.hpp"
#include "operations/echo.hpp"
#include "operations/i_operation.hpp"

class ConveyorParser {
 public:
  void parse(std::string arguments_str);

  void process();

 private:
  static std::pair<std::string, std::string> separateSpaces(
      const std::string& str);

  void addOperation(const std::string& command_str);

  std::stack<std::unique_ptr<IOperation>> operations_;
};

#endif  // CPP_HW2_CONVEYOR_PARSER_HPP
