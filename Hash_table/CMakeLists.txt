cmake_minimum_required(VERSION 3.20)
project(Hash_table)

set(GOOGLETEST_VERSION 1.11.0)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(googletest-master/googletest)

include_directories(googletest-master/googletest/include)
add_executable(Hash_table main.cpp HashTable.cpp HashTable.h Shuffle.h)
target_link_libraries(Hash_table gtest main.cpp)