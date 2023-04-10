cmake_minimum_required(VERSION 3.22)
project(cpp_hw2)

set(CMAKE_CXX_STANDARD 17)

set(INCLUDE_DIR headers)
include_directories(${INCLUDE_DIR})
set(HEADER_FILES ${INCLUDE_DIR}/operations/Cat.hpp ${INCLUDE_DIR}/operations/IOperation.hpp ${INCLUDE_DIR}/operations/Echo.hpp ${INCLUDE_DIR}/operations/Cut.hpp ${INCLUDE_DIR}/Conveyor.hpp)

add_executable(cpp_hw2 ${HEADER_FILES} sources/main.cpp sources/operations/Cat.cpp sources/operations/Echo.cpp sources/operations/Cut.cpp sources/Conveyor.cpp)
