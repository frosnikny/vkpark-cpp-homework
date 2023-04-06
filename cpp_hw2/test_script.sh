mkdir build
cd build || exit
cmake ..
make
cd ..
# Place file text.txt and some text in the "examples" directory
build/cpp_hw2 'echo Hello world! | cat examples/text.txt | cut 2'
