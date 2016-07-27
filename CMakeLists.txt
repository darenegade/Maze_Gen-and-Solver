set(CMAKE_VERBOSE_MAKEFILE ON)
cmake_minimum_required(VERSION 3.5)
project(grp04_algdatII)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(GCC_COVERAGE_LINK_FLAGS "-lmingw32 -lSDLmain -lSDL")


set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_subdirectory(src)
add_executable(grp04_algdatII src/main.cpp)

target_include_directories(grp04_algdatII PUBLIC ${SDL2_INCLUDE_DIR})
target_link_libraries(grp04_algdatII ${SDL2_LIBRARY})