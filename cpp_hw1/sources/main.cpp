#include <iostream>
#include <map>
#include <string>

#include "../headers/arg_utils.hpp"
#include "../headers/task.hpp"

int main(int argc, char* argv[]) {
  int required_best_numbers = 10;
  int max_duration = 0;
  std::map<std::string, std::string> args_filenames =
      handle_args(argc, argv, max_duration);

  try {
    runTask(std::cout, args_filenames["--title-basics-path"],
            args_filenames["--title-episodes-path"],
            args_filenames["--title-ratings-path"],
            args_filenames["--title-akas-path"], max_duration,
            required_best_numbers);
  } catch (std::exception&(e)) {
    std::cerr << "An error occurred while the program was running\n"
              << e.what() << "\n";
    exit(1);
  }

  return 0;
}
