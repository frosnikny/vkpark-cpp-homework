#ifndef CPP_HW2_CONVEYOR_HPP
#define CPP_HW2_CONVEYOR_HPP

#include <memory>
#include <stack>
#include <string>
#include <utility>

#include "operations/Cat.hpp"
#include "operations/Cut.hpp"
#include "operations/Echo.hpp"
#include "operations/IOperation.hpp"

class Conveyor {
 public:
  void buildFromString(std::string arguments_str);

  void process();

 private:
  static std::pair<std::string, std::string> separateSpaces(
      const std::string& str);

  void addOperation(const std::string& command_str);

  std::stack<std::unique_ptr<IOperation>> operations_;
};

#endif  // CPP_HW2_CONVEYOR_HPP
