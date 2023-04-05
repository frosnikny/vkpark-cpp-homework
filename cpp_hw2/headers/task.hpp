#ifndef CPP_HW2_TASK_HPP
#define CPP_HW2_TASK_HPP

#include <memory>
#include <stack>
#include <string>
#include <utility>

#include "operations/cat.hpp"
#include "operations/cut.hpp"
#include "operations/echo.hpp"
#include "operations/i_operation.hpp"

void runTask(std::stack<std::pair<std::string, std::string>> arguments);

#endif  // CPP_HW2_TASK_HPP
