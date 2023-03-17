cmake_minimum_required(VERSION 3.22)
project(cpp_hw1)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_hw1 sources/main.cpp sources/read_files.cpp headers/read_files.hpp sources/exercise.cpp headers/exercise.hpp headers/tv_serial.hpp sources/errors.cpp headers/errors.hpp)
