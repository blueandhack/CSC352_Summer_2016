cmake_minimum_required(VERSION 3.5)
project(Assignment_3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES sim.c)
set(SOURCE2_FILES part.c)
set(SOURCE3_FILES editor.c)
add_executable(sim ${SOURCE_FILES})
add_executable(part ${SOURCE2_FILES})
add_executable(editor ${SOURCE3_FILES})