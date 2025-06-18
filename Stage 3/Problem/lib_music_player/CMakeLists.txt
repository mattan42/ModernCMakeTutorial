project(lib_music_player)

# Adding the library
add_library(music_player INTERFACE)

target_include_directories(music_player PUBLIC ./include)
