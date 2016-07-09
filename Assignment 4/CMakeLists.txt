cmake_minimum_required(VERSION 3.5)
project(Assignment_4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES driver.c llist.h llist.c)
set(SOURCE1_FILES mru.c llist.h llist.c)
add_executable(driver ${SOURCE_FILES})
add_executable(mru ${SOURCE1_FILES})