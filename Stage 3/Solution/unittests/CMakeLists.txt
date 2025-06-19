cmake_minimum_required(VERSION 3.28)
project(stage_3_unittests)

# Getting googletest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# From the "FetchContent" docs:
# "This command ensures that each of the named dependencies are made available 
# to the project by the time it returns"
FetchContent_MakeAvailable(googletest)

add_executable(unittests ./test.cpp)

# Link the project's library of course
target_link_libraries(unittests 
    PUBLIC multi_music_player)

# Since we ran `FetchContent`, we don't need to visit the subdirectory ourselves,
# this was already performed by `MakeAvailable`, so we can just link to `gtest_main`
# (which is the library version with an existing `main` function, so we don't have to
# define one ourselves)
target_link_libraries(unittests 
    PUBLIC GTest::gtest_main)
