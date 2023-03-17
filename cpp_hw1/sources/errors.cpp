#include "../headers/errors.hpp"

void reportError(const std::exception& e, char* program_name) {
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
