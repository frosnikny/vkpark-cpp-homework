#include "../headers/read_files.hpp"

// function for reading episodes from title.episode.tsv
void Parser::ReadEpisodes(
    const std::string& filename,
    std::unordered_map<std::string, TVSerial>& serials,
    std::unordered_map<std::string, int>& episode_durations) {
  std::ifstream file(filename, std::ios::binary);
  if (!file.is_open()) {
    throw std::invalid_argument("Cannot open file " + filename);
  }

  std::string line;
  // Read header
  std::getline(file, line);
  if (line != "tconst\tparentTconst\tseasonNumber\tepisodeNumber") {
    throw std::invalid_argument("Invalid file " + filename + " passed");
  }

  std::string episode_id{};
  std::string parent_episode_id{};
  while (std::getline(file, line)) {
    std::istringstream line_stream(line);
    std::getline(line_stream, episode_id, '\t');
    std::getline(line_stream, parent_episode_id, '\t');
    auto find_serial = serials.find(parent_episode_id);
    if (find_serial == serials.end()) {
      find_serial = (serials.emplace(parent_episode_id, TVSerial())).first;
    }
    episode_durations.emplace(episode_id, 0);
    find_serial->second.episode_numbers.push_back(episode_id);
  }
}

// function for reading info from title.basics.tsv
void Parser::ReadSerials(
    const std::string& filename,
    std::unordered_map<std::string, TVSerial>& serials,
    std::unordered_map<std::string, int>& episode_durations) {
  std::ifstream file(filename, std::ios::binary);
  if (!file.is_open()) {
    throw std::invalid_argument("Cannot open file " + filename);
  }

  std::string line;
  // Read header
  std::getline(file, line);
  if (line !=
      "tconst\ttitleType\tprimaryTitle\toriginalTitle\tisAdult\tstartYear\t"
      "endYear\truntimeMinutes\tgenres") {
    throw std::invalid_argument("Invalid file " + filename + " passed");
  }

  std::string item_id{};
  // String for skipping columns
  std::string skip{};
  std::string primary_title{};
  std::string is_adult{};
  std::string runtime_minutes{};
  bool has_found_serial = false;
  while (std::getline(file, line)) {
    std::istringstream line_stream(line);
    std::getline(line_stream, item_id, '\t');
    const auto& serial_find = serials.find(item_id);
    const auto& episode_find = episode_durations.find(item_id);
    if (serial_find != serials.end()) {
      has_found_serial = true;
    } else if (episode_find != episode_durations.end()) {
      has_found_serial = false;
    } else {
      continue;
    }
    // skip "titleType" column
    std::getline(line_stream, skip, '\t');
    std::getline(line_stream, primary_title, '\t');
    // skip "originalTitle" column
    std::getline(line_stream, skip, '\t');
    std::getline(line_stream, is_adult, '\t');
    if (is_adult == "1") {
      if (has_found_serial) {
        serials.erase(serial_find);
      } else {
        episode_durations.erase(episode_find);
      }
      continue;
    }
    // skip "startYear" column
    std::getline(line_stream, skip, '\t');
    // skip "endYear" column
    std::getline(line_stream, skip, '\t');
    std::getline(line_stream, runtime_minutes, '\t');
    if (has_found_serial) {
      serial_find->second.average_episode_duration =
          (runtime_minutes != "\\N") ? std::stoi(runtime_minutes) : 0;
      serial_find->second.title = primary_title;
    } else {
      episode_find->second =
          (runtime_minutes != "\\N") ? std::stoi(runtime_minutes) : 0;
    }
  }
}

// function for reading ratings from title.ratings.tsv
void Parser::ReadRatings(const std::string& filename,
                         std::unordered_map<std::string, TVSerial>& serials) {
  std::ifstream file(filename, std::ios::binary);
  if (!file.is_open()) {
    throw std::invalid_argument("Cannot open file " + filename);
  }

  std::string line;
  // Read header
  std::getline(file, line);
  if (line != "tconst\taverageRating\tnumVotes") {
    throw std::invalid_argument("Invalid file " + filename + " passed");
  }

  std::string serial_id{};
  std::string average_rating_str{};
  std::string num_votes_str{};
  int num_votes{};
  double avg_rating{};
  while (std::getline(file, line)) {
    std::istringstream line_stream(line);
    std::getline(line_stream, serial_id, '\t');
    const auto& serial_find = serials.find(serial_id);
    if (serial_find == serials.end()) {
      continue;
    }
    std::getline(line_stream, average_rating_str, '\t');
    avg_rating =
        average_rating_str != "\\N" ? std::stod(average_rating_str) : 0;
    std::getline(line_stream, num_votes_str, '\t');
    num_votes = num_votes_str != "\\N" ? std::stoi(num_votes_str) : 0;
    if (num_votes < 1000) {
      serials.erase(serial_find);
    } else {
      serial_find->second.avg_rating = avg_rating;
    }
  }
}

// function for reading episodes from title.akas.tsv
void Parser::ReadAkas(const std::string& filename,
                      std::vector<TVSerialPair>& serials) {
  std::ifstream file(filename, std::ios::binary);
  if (!file.is_open()) {
    throw std::invalid_argument("Cannot open file " + filename);
  }

  std::string line;
  // Read header
  std::getline(file, line);
  if (line !=
      "titleId\tordering\ttitle\tregion\tlanguage\ttypes\tattributes\t"
      "isOriginalTitle") {
    throw std::invalid_argument("Invalid file " + filename + " passed");
  }

  std::string serial_id{};
  std::string translated_title{};
  std::string region{};
  std::string language{};
  // String for skipping columns
  std::string skip{};
  while (std::getline(file, line)) {
    std::istringstream line_stream(line);
    std::getline(line_stream, serial_id, '\t');
    const auto& serials_fin = std::find_if(
        serials.begin(), serials.end(), [serial_id](const TVSerialPair& item) {
          return item.first == serial_id;
        });
    if (serials_fin == serials.end()) {
      continue;
    }
    // skip "ordering" column
    std::getline(line_stream, skip, '\t');
    std::getline(line_stream, translated_title, '\t');
    std::getline(line_stream, region, '\t');
    std::getline(line_stream, language, '\t');
    if (region == "RU" || language == "ru") {
      serials_fin->second.ru_title = translated_title;
    }
  }
}
