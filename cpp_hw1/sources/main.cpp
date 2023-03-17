#include <iostream>
#include <limits>
#include <string>

#include "../headers/errors.hpp"
#include "../headers/exercise.hpp"

void take_args(int argc, char* argv[], std::string& basics_filename,
               std::string& episodes_filename, std::string& ratings_filename,
               std::string& akas_filename, int& max_duration);

int main(int argc, char* argv[]) {
  if (argc != 11) {
    reportInvalidArgumentError(
        std::invalid_argument("Invalid number of arguments received"), argv[0]);
  }
  std::string basics_filename{};
  std::string episodes_filename{};
  std::string ratings_filename{};
  std::string akas_filename{};
  int max_duration{};
  take_args(argc, argv, basics_filename, episodes_filename, ratings_filename,
            akas_filename, max_duration);
  if (basics_filename.empty() || episodes_filename.empty() ||
      ratings_filename.empty() || akas_filename.empty()) {
    reportInvalidArgumentError(
        std::invalid_argument("The necessary arguments were not received"),
        argv[0]);
  }
  if (max_duration <= 0) {
    std::cerr << "The --max_duration argument should be greater than 0\n";
    exit(1);
  }
  int required_best_numbers = 10;

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

void take_args(int argc, char* argv[], std::string& basics_filename,
               std::string& episodes_filename, std::string& ratings_filename,
               std::string& akas_filename, int& max_duration) {
  for (int i = 1; i < argc; ++i) {
    std::string arg = argv[i];
    if (arg == "--title-basics-path") {
      basics_filename = argv[++i];
    } else if (arg == "--title-episodes-path") {
      episodes_filename = argv[++i];
    } else if (arg == "--title-ratings-path") {
      ratings_filename = argv[++i];
    } else if (arg == "--title-akas-path") {
      akas_filename = argv[++i];
    } else if (arg == "--max_duration") {
      try {
        max_duration = std::stoi(argv[++i]);
      } catch (std::invalid_argument&(e)) {
        reportInvalidArgumentError(
            std::invalid_argument(
                "The --max_duration argument has the wrong type"),
            argv[0]);
      } catch (std::out_of_range&(e)) {
        std::cerr << "Too large number passed by --max_duration argument (Use "
                     "number < "
                  << std::numeric_limits<int>::max() << ")\n";
        exit(1);
      } catch (std::exception&(e)) {
        std::cerr << "Error during processing of argument --max_duration\n"
                  << e.what();
        exit(1);
      }
    }
  }
}
