cmake_minimum_required(VERSION 3.20)
project(VirusWar)

set(CMAKE_CXX_STANDARD 20)

add_executable(VirusWar main.cpp Game.cpp Game.h Controller.cpp Controller.h View.cpp View.h gameException.h Player.h Human.cpp Human.h Bot.cpp Bot.h PlayerManufacturer.cpp PlayerManufacturer.h)
