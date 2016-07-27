cmake_minimum_required(VERSION 3.5)
project(Assignment_6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES wf.c hashtable.h hashtable.c)
add_executable(wf ${SOURCE_FILES})