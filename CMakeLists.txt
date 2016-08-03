cmake_minimum_required(VERSION 2.8)

project(grp04-algdatII)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fprofile-arcs -ftest-coverage")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -fprofile-arcs -ftest-coverage")
else()
    message(ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

#set(SDL2_LIBRARY C:/Users/peter-mueller/Documents/hm-ss16/algdat2/grp04-algdatII/lib/SDL2.dll)

include_directories(
        ${PROJECT_SOURCE_DIR}/src
)

add_subdirectory(src)

add_executable(
        grp04-algdatII
        src/main.cpp
)

add_library(grp04-algdatII-lib
        src/main.cpp
        )

target_link_libraries(
        grp04-algdatII
        visualizer
        Algorithm
        ${SDL2_LIBRARY}
)


set(GOOGLETEST_ROOT external/googletest/googletest CACHE STRING "Google Test source root")

include_directories(
        ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}
        ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/include
)

set(GOOGLETEST_SOURCES
        ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest-all.cc
        ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest_main.cc
        )

foreach(_source ${GOOGLETEST_SOURCES})
    set_source_files_properties(${_source} PROPERTIES GENERATED 1)
endforeach()

add_library(googletest ${GOOGLETEST_SOURCES})

add_executable(
        unit_tests
        src/test/main.cpp
        src/test/generator-test.cpp)


add_dependencies(unit_tests googletest)

target_link_libraries(
        unit_tests
        googletest
        grp04-algdatII-lib
        pthread
)

include(CTest)
enable_testing()

add_test(unit ${PROJECT_BINARY_DIR}/unit_tests)
