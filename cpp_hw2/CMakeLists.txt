cmake_minimum_required(VERSION 3.25)
project(cpp_hw2)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_hw2 sources/main.cpp sources/operations/cat.cpp headers/operations/cat.hpp headers/operations/i_operation.hpp sources/operations/echo.cpp headers/operations/echo.hpp sources/operations/cut.cpp headers/operations/cut.hpp sources/arg_utils.cpp headers/arg_utils.hpp sources/task.cpp headers/task.hpp)
