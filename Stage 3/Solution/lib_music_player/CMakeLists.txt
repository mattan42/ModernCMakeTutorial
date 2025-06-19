cmake_minimum_required(VERSION 3.28)
project(lib_music_player)

# Adding the library
add_library(music_player INTERFACE)

# Adding the headers to the library target
target_include_directories(music_player INTERFACE ./include)
