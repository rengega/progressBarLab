cmake_minimum_required(VERSION 3.12)
project(ProgressBarLab)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(test)

add_executable(ProgressBarLab main.cpp)