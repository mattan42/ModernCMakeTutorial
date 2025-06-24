cmake_minimum_required(VERSION 3.28)
project(stage_4)

# Checking if user tries generating a multi-config build system
get_property(isMultiConfig GLOBAL
    PROPERTY GENERATOR_IS_MULTI_CONFIG
)
    
if(isMultiConfig)
    # We don't support that
    message(FATAL_ERROR "This CMakeLists.txt doesn't support multi-config bulid systems")
else()
    set(allowedBuildTypes DEBUG RELEASE WARNING)

    # If the CMAKE_BUILD_TYPE wasn't specified, force a Debug build.
    if(NOT CMAKE_BUILD_TYPE)
        message(FATAL_ERROR "User has to provide a build-type. Please choose one of the following ${allowedBuildTypes}")
    # If user specified an unknown CMAKE_BUILD_TYPE
    elseif(NOT CMAKE_BUILD_TYPE IN_LIST allowedBuildTypes)
        message(FATAL_ERROR
            "Unknown build type: ${CMAKE_BUILD_TYPE}. Please choose one of the following: ${allowedBuildTypes}"
        )
    endif()
endif()

# Notice that this variable is not a list but a string
set(CMAKE_CXX_FLAGS_DEBUG
    "-g ${CMAKE_CXX_FLAGS_DEBUG}"
)

set(CMAKE_CXX_FLAGS_RELEASE
    "-O3 ${CMAKE_CXX_FLAGS_RELEASE}"
)

# This is our custom build-target.
set(CMAKE_CXX_FLAGS_WARNING
    "-Wall"
)

add_subdirectory(lib_music_player)
add_subdirectory(lib_spotify_player)

add_library(multi_music_player ./src/multi_music_player.cpp)
target_include_directories(multi_music_player PUBLIC ./include)

target_link_libraries(multi_music_player
    PUBLIC music_player
    PUBLIC spotify_player)

add_executable(multi_music_player_gui ./src/main.cpp)
target_link_libraries(multi_music_player_gui PUBLIC multi_music_player)

add_subdirectory(unittests)
