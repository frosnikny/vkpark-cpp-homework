#include "../headers/exercise.hpp"

// Count the total duration of all episodes of serials
void DurationCalculate(std::unordered_map<std::string, TVSerial>& serials,
                       std::unordered_map<std::string, int>& episode_durations,
                       int max_duration) {
  std::vector<std::string> serials_for_delete{};
  for (auto& serial : serials) {
    int summary{0};
    for (const auto& episode_id : serial.second.episode_numbers) {
      auto map_episode = episode_durations.find(episode_id);
      if (map_episode == episode_durations.end()) {
        continue;
      }
      if (map_episode->second == 0) {
        // if the duration of the episode isn't found,
        // we take serial's average duration from table instead of it
        map_episode->second = serial.second.average_episode_duration;
      }
      summary += map_episode->second;
    }
    if (summary > max_duration || summary == 0) {
      serials_for_delete.push_back(serial.first);
    }
  }

  for (auto& i : serials_for_delete) {
    serials.erase(i);
  }
}

bool RatingComparator(const TVSerialPair& a, const TVSerialPair& b) {
  return a.second.avg_rating > b.second.avg_rating;
}

void TakeBestRatings(
    const std::unordered_map<std::string, TVSerial>& serials,
    std::priority_queue<TVSerialPair, std::vector<TVSerialPair>,
                        decltype(&RatingComparator)>& best_serials_pq,
    int required_number) {
  for (auto& elem : serials) {
    best_serials_pq.emplace(elem.first, elem.second);
    if (best_serials_pq.size() > required_number) {
      best_serials_pq.pop();
    }
  }
}

void RunExercise(std::ostream& out, const std::string& basics_filename,
                 const std::string& episodes_filename,
                 const std::string& ratings_filename,
                 const std::string& akas_filename, int max_duration,
                 int required_bests_number) {
  std::unordered_map<std::string, TVSerial> serials{};
  std::unordered_map<std::string, int> episode_durations{};

  // Take main information about serials and episodes
  Parser::ReadEpisodes(episodes_filename, serials, episode_durations);
  Parser::ReadSerials(basics_filename, serials, episode_durations);
  DurationCalculate(serials, episode_durations, max_duration);
  Parser::ReadRatings(ratings_filename, serials);

  // Take required number of the best rating episodes in descending order
  //  typedef std::pair<std::string, TVSerial> TVSerialPair;
  std::priority_queue<TVSerialPair, std::vector<TVSerialPair>,
                      decltype(&RatingComparator)>
      best_serials_pq(&RatingComparator);
  TakeBestRatings(serials, best_serials_pq, required_bests_number);
  std::vector<TVSerialPair> best_serials_vec(required_bests_number);
  for (int i = required_bests_number - 1; i > -1; --i) {
    best_serials_vec[i] = best_serials_pq.top();
    best_serials_pq.pop();
  }

  // Take Russian title only for required number of serials
  Parser::ReadAkas(akas_filename, best_serials_vec);

  // Display all the necessary information
  out << "Топ " << required_bests_number
      << " самых рейтинговых сериалов с суммарной длительностью всех "
         "эпизодов, не превышающей "
      << max_duration << " минут:\n";
  for (int i = 0; i < required_bests_number; ++i) {
    out << i + 1 << ". ";
    if (!best_serials_vec[i].second.ru_title.empty()) {
      out << best_serials_vec[i].second.ru_title << " ";
    } else {
      out << best_serials_vec[i].second.title << " ";
    }
    out << " - " << best_serials_vec[i].second.avg_rating << "\n";
  }
}
