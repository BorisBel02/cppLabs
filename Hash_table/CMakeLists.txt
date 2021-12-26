cmake_minimum_required(VERSION 3.20)
project(Hash_table)

set(GOOGLETEST_VERSION 1.11.0)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory (lib/googletest-master)

include_directories (lib/googletest-master/googletest/include)
include_directories (lib/googletest-master/googlemock/include)

add_executable(Hash_table main.cpp HashTable.cpp HashTable.h Shuffle.h AtException.h)

target_link_libraries (Hash_table gtest gtest_main)