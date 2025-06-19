cmake_minimum_required(VERSION 3.28)
project(stage_3)

# Visiting the dependencies sub-directories in order to create the
# targets before linking against them.
add_subdirectory(lib_music_player)
add_subdirectory(lib_spotify_player)

# Adding the project's library
add_library(multi_music_player ./src/multi_music_player.cpp)
target_include_directories(multi_music_player PUBLIC ./include)

# Linking to the dependencies
target_link_libraries(multi_music_player
    PUBLIC music_player
    PUBLIC spotify_player)

add_executable(multi_music_player_gui ./src/main.cpp)
target_link_libraries(multi_music_player_gui PUBLIC multi_music_player)

add_subdirectory(unittests)
