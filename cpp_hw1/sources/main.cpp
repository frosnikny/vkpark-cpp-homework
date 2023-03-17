#include <iostream>
#include <limits>
#include <string>

#include "../headers/errors.hpp"
#include "../headers/exercise.hpp"

int main(int argc, char* argv[]) {
  if (argc != 6) {
    reportInvalidArgumentError(
        std::invalid_argument("Invalid number of arguments received"), argv[0]);
  }

  std::string basics_filename{argv[1]};
  std::string episodes_filename{argv[2]};
  std::string ratings_filename{argv[3]};
  std::string akas_filename{argv[4]};
  int max_duration{};
  int required_best_numbers = 10;
  try {
    max_duration = std::stoi(argv[5]);
  } catch (std::invalid_argument&(e)) {
    reportInvalidArgumentError(
        std::invalid_argument("The 5 argument has the wrong type"), argv[0]);
  } catch (std::out_of_range&(e)) {
    std::cerr << "Too large number passed by 5 argument (Use number < "
              << std::numeric_limits<int>::max() << ")\n";
    exit(1);
  } catch (std::exception&(e)) {
    std::cerr << "Error during processing of argument 5\n" << e.what();
    exit(1);
  }

  try {
    runTask(std::cout, basics_filename, episodes_filename, ratings_filename,
            akas_filename, max_duration, required_best_numbers);
  } catch (std::exception&(e)) {
    std::cerr << "An error occurred while the program was running\n"
              << e.what() << "\n";
    exit(1);
  }
  return 0;
}
