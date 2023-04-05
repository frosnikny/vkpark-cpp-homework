#include <map>
#include <stack>
#include <utility>

#include "../headers/arg_utils.hpp"
#include "../headers/task.hpp"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    throw std::invalid_argument("Invalid number of arguments passed");
  }
  std::string arguments_str(argv[1]);
  try {
    std::stack<std::pair<std::string, std::string>> arguments =
        take_args(arguments_str);
    runTask(arguments);
  } catch (std::exception&) {
    throw;
  }
  return 0;
}
