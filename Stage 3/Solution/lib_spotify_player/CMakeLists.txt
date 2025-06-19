cmake_minimum_required(VERSION 3.28)
project(lib_spotify_player)

add_library(spotify_player ./src/spotify_player.cpp)

# This will be relevant in step 4. Ignore it if you're not there yet :)
set(PLATFORM_HAS_BLUETOOTH ON)
if(PLATFORM_HAS_BLUETOOTH)
    # We want to add the bluetooth feature to our spotify player here!
    target_compile_definitions(spotify_player PUBLIC SPOTIFY_ENABLE_BLUETOOTH)
endif()

target_include_directories(spotify_player PUBLIC ./include)

if(${PROJECT_NAME} STREQUAL ${CMAKE_PROJECT_NAME})
    # If this is the root project, then we would need to include `lib_music_player` ourselves and
    # not rely on a parent CMake to add the target for us.
endif()

target_link_libraries(spotify_player PUBLIC music_player)
