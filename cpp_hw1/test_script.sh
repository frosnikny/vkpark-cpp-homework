mkdir build
cd build || exit
cmake ..
make
cd ..
# Place files with standard names in the "imdb" directory
build/cpp_hw1 --title-basics-path imdb/title.basics.tsv --title-episodes-path imdb/title.episode.tsv --title-ratings-path imdb/title.ratings.tsv --title-akas-path imdb/title.akas.tsv --max_duration 500
