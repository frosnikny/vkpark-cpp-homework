#include <map>
#include <stack>
#include <utility>

#include "arg_utils.hpp"
#include "task.hpp"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    throw std::invalid_argument("Invalid number of arguments passed");
  }
  std::string arguments_str(argv[1]);
  try {
    std::stack<std::pair<std::string, std::string>> arguments =
        take_args(arguments_str);
    runTask(arguments);
  } catch (std::exception&(e)) {
    std::cerr << "An error occurred while the program was running\n"
              << e.what() << "\n";
    return 1;
  }
  return 0;
}
