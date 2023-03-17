#include <iostream>
#include <string>

#include "../headers/errors.hpp"
#include "../headers/exercise.hpp"

int main(int argc, char* argv[]) {
  if (argc != 6) {
    reportError(std::invalid_argument("Invalid number of arguments received"),
                argv[0]);
  }
  try {
    std::string basics_filename{argv[1]};
    std::string episodes_filename{argv[2]};
    std::string ratings_filename{argv[3]};
    std::string akas_filename{argv[4]};
    int max_duration = std::stoi(argv[5]);
    runTask(std::cout, basics_filename, episodes_filename, ratings_filename,
            akas_filename, max_duration, 10);
  } catch (const std::exception& e) {
    reportError(e, argv[0]);
  }
  return 0;
}
