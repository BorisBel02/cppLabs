cmake_minimum_required(VERSION 3.20)
project(CSV_Parser)

set(CMAKE_CXX_STANDARD 20)

add_executable(CSV_Parser main.cpp Parser.cpp Parser.h ParseException.h)
