#include <string>

#include "Conveyor.hpp"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Invalid number of arguments passed\n";
    return 1;
  }
  try {
    std::string arguments_str(argv[1]);
    Conveyor parser;
    parser.buildFromString(arguments_str);
    parser.process();
  } catch (std::exception&(e)) {
    std::cerr << "An error occurred while the program was running\n"
              << e.what() << "\n";
    return 1;
  }
  return 0;
}
