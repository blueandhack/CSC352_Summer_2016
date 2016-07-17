cmake_minimum_required(VERSION 3.5)
project(Assignment_5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES scores.c player.c player.h)
add_executable(scores ${SOURCE_FILES})