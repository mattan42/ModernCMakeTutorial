project(lib_spotify_player)

add_library(spotify_player ./src/spotify_player.cpp)

# This will be relevant in step 4. Ignore it if you're not there yet :)
set(PLATFORM_HAS_BLUETOOTH OFF)
if(PLATFORM_HAS_BLUETOOTH)
    # We want to add the bluetooth feature to our spotify player here!
endif()
