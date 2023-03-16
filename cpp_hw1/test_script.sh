mkdir build
cd build || exit
cmake ..
make
cd ..
# Place files with standard names in the "imdb" directory
build/cpp_hw1 imdb/title.basics.tsv imdb/title.episode.tsv imdb/title.ratings.tsv imdb/title.akas.tsv 500
