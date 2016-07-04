cmake_minimum_required(VERSION 3.5)
project(Assignment_4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES driver.c)
add_executable(Assignment_4 ${SOURCE_FILES})