#include "../headers/errors.hpp"

void reportInvalidArgumentError(const std::exception& e, char* program_name) {
  std::cerr << "Error: " << e.what() << "\nUsage: " << program_name
            << " --title-basics-path <basics_filename> "
               "--title-episodes-path <episodes_filename> "
               "--title-ratings-path <ratings_filename> --title-akas-path "
               "<akas_filename> --max_duration <maximum_duration>\n"
               "where:\n"
               "  <basics_filename>      - name of file containing movie "
               "information\n"
               "  <episodes_filename>    - name of file containing TV "
               "series information\n"
               "  <ratings_filename>     - name of file containing movie "
               "and TV series ratings\n"
               "  <akas_filename>        - name of file containing "
               "alternative titles for movies and TV series\n"
               "  <maximum_duration>     - maximum duration of all series of"
               "TV series to consider (in minutes)"
            << std::endl;
  exit(1);
}
