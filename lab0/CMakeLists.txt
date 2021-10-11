cmake_minimum_required(VERSION 3.20)
project(lab0)

set(CMAKE_CXX_STANDARD 23)

add_executable(lab0 main.cpp Parse.h Parse.cpp)

set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CSS_STANDARD_LIBRARIES}")

set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")