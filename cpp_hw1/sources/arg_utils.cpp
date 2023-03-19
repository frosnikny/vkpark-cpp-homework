#include "../headers/arg_utils.hpp"

std::map<std::string, std::string> take_args(int argc, char* argv[]) {
  std::map<std::string, std::string> arguments{};
  for (int i = 1; i < argc; ++i) {
    std::string arg = argv[i];
    if (arg.substr(0, 2) == "--") {
      arguments[arg] = argv[++i];
    }
  }
  return std::move(arguments);
}

std::map<std::string, std::string> handle_args(int argc, char* argv[],
                                               int& max_duration) {
  if (argc != 11) {
    reportInvalidArgumentError(
        std::invalid_argument("Invalid number of arguments received"), argv[0]);
  }

  std::map<std::string, std::string> args_filenames = take_args(argc, argv);
  if (args_filenames.find("--title-basics-path") == args_filenames.end() ||
      args_filenames.find("--title-episodes-path") == args_filenames.end() ||
      args_filenames.find("--title-ratings-path") == args_filenames.end() ||
      args_filenames.find("--title-akas-path") == args_filenames.end() ||
      args_filenames.find("--max_duration") == args_filenames.end()) {
    reportInvalidArgumentError(
        std::invalid_argument("The necessary arguments were not received"),
        argv[0]);
  }

  try {
    max_duration = std::stoi(args_filenames["--max_duration"]);
  } catch (std::invalid_argument&(e)) {
    reportInvalidArgumentError(
        std::invalid_argument("The --max_duration argument has the wrong type"),
        argv[0]);
  } catch (std::out_of_range&(e)) {
    std::cerr << "Too large number passed by --max_duration argument (Use"
                 "number < "
              << std::numeric_limits<int>::max() << ")\n";
    exit(1);
  } catch (std::exception&(e)) {
    std::cerr << "Error during processing of argument --max_duration\n"
              << e.what();
    exit(1);
  }

  if (max_duration <= 0) {
    std::cerr << "The --max_duration argument should be greater than 0\n";
    exit(1);
  }

  return std::move(args_filenames);
}
