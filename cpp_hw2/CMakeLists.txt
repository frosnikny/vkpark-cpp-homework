cmake_minimum_required(VERSION 3.25)
project(cpp_hw2)

set(CMAKE_CXX_STANDARD 17)

set(INCLUDE_DIR headers)
include_directories(${INCLUDE_DIR})
set(HEADER_FILES ${INCLUDE_DIR}/operations/cat.hpp ${INCLUDE_DIR}/operations/i_operation.hpp ${INCLUDE_DIR}/operations/echo.hpp ${INCLUDE_DIR}/operations/cut.hpp ${INCLUDE_DIR}/task.hpp ${INCLUDE_DIR}/conveyor_parser.hpp)

add_executable(cpp_hw2 ${HEADER_FILES} sources/main.cpp sources/operations/cat.cpp sources/operations/echo.cpp sources/operations/cut.cpp sources/task.cpp sources/conveyor_parser.cpp)
