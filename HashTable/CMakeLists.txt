cmake_minimum_required(VERSION 3.20)
project(HashTable)

set(CMAKE_CXX_STANDARD 23)

add_executable(HashTable main.cpp HashTable.cpp HashTable.h Shuffle.h)
