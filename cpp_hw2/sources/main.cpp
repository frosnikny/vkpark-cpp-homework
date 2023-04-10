#include <stack>

#include "task.hpp"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Invalid number of arguments passed\n";
    return 1;
  }
  std::string arguments_str(argv[1]);
  try {
    runTask(arguments_str);
  } catch (std::exception&(e)) {
    std::cerr << "An error occurred while the program was running\n"
              << e.what() << "\n";
    return 1;
  }
  return 0;
}
