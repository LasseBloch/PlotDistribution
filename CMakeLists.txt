cmake_minimum_required(VERSION 3.6)
project(RandomNumberDistribution)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

set(SOURCE_FILES main.cpp scr/game.cpp scr/game.h scr/dataGenerator.cpp scr/dataGenerator.h)
add_executable(RandomNumberDistribution ${SOURCE_FILES})
target_link_libraries(RandomNumberDistribution ${SDL2_LIBRARY})
