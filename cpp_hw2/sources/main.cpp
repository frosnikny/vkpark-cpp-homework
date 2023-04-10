#include <stack>

#include "task.hpp"

// TODO: Что-то не работает с несколькими строчками в cat->cut

int main(int argc, char* argv[]) {
  if (argc != 2) {
    throw std::invalid_argument("Invalid number of arguments passed");
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
