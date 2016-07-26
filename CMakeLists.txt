cmake_minimum_required(VERSION 3.5)
project(grp04_algdatII)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_subdirectory(Visualizer)
add_subdirectory(LabGenerator)
add_subdirectory(Algorithm)
add_executable(grp04_algdatII ${SOURCE_FILES})