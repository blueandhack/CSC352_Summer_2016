cmake_minimum_required(VERSION 3.5)
project(Assignment_3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES sim.c)
add_executable(Assignment_3 ${SOURCE_FILES})