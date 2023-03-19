#include "../headers/task.hpp"

void runTask(std::ostream& out, const std::string& basics_filename,
             const std::string& episodes_filename,
             const std::string& ratings_filename,
             const std::string& akas_filename, int max_duration,
             int required_best_number) {
  SerialsCollection collection{};

  // Take main information about serials and episodes
  Parser::readEpisodes(episodes_filename, collection);
  Parser::readSerials(basics_filename, collection);
  calculateDuration(collection, max_duration);
  Parser::readRatings(ratings_filename, collection);

  // Take required number of the best rating episodes in descending order
  auto best_serials_vec = takeBestRatings(collection, required_best_number);

  // Take Russian title only for required number of serials
  Parser::readAkas(akas_filename, best_serials_vec);
  // Display all the necessary information
  out << "Топ " << required_best_number
      << " самых рейтинговых сериалов с суммарной длительностью всех "
         "эпизодов, не превышающей "
      << max_duration << " минут:\n";
  for (int i = 0; i < required_best_number; ++i) {
    out << i + 1 << ". ";
    if (!best_serials_vec[i].second.ru_title.empty()) {
      out << best_serials_vec[i].second.ru_title << " ";
    } else {
      out << best_serials_vec[i].second.title << " ";
    }
    out << " - " << best_serials_vec[i].second.avg_rating << "\n";
  }
}

// Count the total duration of all episodes of serials
void calculateDuration(SerialsCollection& collection, int max_duration) {
  auto& serials = collection.getSerials();
  auto& episode_durations = collection.getEpisodeDurations();

  std::vector<std::string> serials_for_delete{};
  for (const auto& serial : serials) {
    int summary{0};
    for (const auto& episode_id : serial.second.episode_numbers) {
      auto current_episode_duration = episode_durations.find(episode_id);
      if (current_episode_duration == episode_durations.end()) {
        continue;
      }
      if (current_episode_duration->second == 0) {
        // if the duration of the episode isn't found,
        // we take serial's average duration from table instead of it
        current_episode_duration->second =
            serial.second.average_episode_duration;
      }
      summary += current_episode_duration->second;
    }
    if (summary > max_duration || summary == 0) {
      serials_for_delete.push_back(serial.first);
    }
  }

  for (auto& i : serials_for_delete) {
    serials.erase(i);
  }
}

bool compareRatings(const SerialsCollection::TVSerialPair& a,
                    const SerialsCollection::TVSerialPair& b) {
  return a.second.avg_rating > b.second.avg_rating;
}

std::vector<SerialsCollection::TVSerialPair> takeBestRatings(
    const SerialsCollection& collection, int required_number) {
  std::priority_queue<SerialsCollection::TVSerialPair,
                      std::vector<SerialsCollection::TVSerialPair>,
                      decltype(&compareRatings)>
      best_serials_pq(compareRatings);
  const auto& serials = collection.getSerials();
  for (const auto& elem : serials) {
    best_serials_pq.emplace(elem.first, elem.second);
    if (best_serials_pq.size() > required_number) {
      best_serials_pq.pop();
    }
  }

  std::vector<SerialsCollection::TVSerialPair> best_serials_vec(
      required_number);
  for (int i = required_number - 1; i > -1; --i) {
    best_serials_vec[i] = best_serials_pq.top();
    best_serials_pq.pop();
  }
  return std::move(best_serials_vec);
}
