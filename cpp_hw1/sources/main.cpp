#include "../headers/main.hpp"

int main(int argc, char* argv[]) {
  if (argc != 6) {
    report_error(std::invalid_argument("Invalid number of arguments received"),
                 argv[0]);
  }
  try {
    std::string basics_filename{argv[1]};
    std::string episodes_filename{argv[2]};
    std::string ratings_filename{argv[3]};
    std::string akas_filename{argv[4]};
    int max_duration = std::stoi(argv[5]);
    RunExercise(std::cout, basics_filename, episodes_filename, ratings_filename,
                akas_filename, max_duration, 10);
  } catch (const std::exception& e) {
    report_error(e, argv[0]);
  }
  return 0;
}

void report_error(const std::exception& e, char* program_name) {
  std::cerr << "Error: " << e.what() << "\nUsage: " << program_name
            << " ./my_program <basics_filename> <episodes_filename> "
               "<ratings_filename> <akas_filename> <maximum_duration>\n"
               "where:\n"
               "  <basics_filename>      - name of file containing movie "
               "information\n"
               "  <episodes_filename>    - name of file containing TV "
               "series information\n"
               "  <ratings_filename>     - name of file containing movie "
               "and TV series ratings\n"
               "  <akas_filename>        - name of file containing "
               "alternative titles for movies and TV series\n"
               "  <maximum_duration>     - maximum duration of a movie or "
               "TV series to consider (in minutes)"
            << std::endl;
  exit(1);
}
