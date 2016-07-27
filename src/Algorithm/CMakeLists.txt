set(SOURCE_FILES BacktrackTest.cpp)

add_library(Algorithm Backtracker.h Backtracker.cpp)

add_executable(BacktrackTest ${SOURCE_FILES})

target_link_libraries(BacktrackTest Algorithm)