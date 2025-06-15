cmake_minimum_required(VERSION 3.28)
project(stage_2)

# Collecting all the library sources
file(GLOB_RECURSE ${PROJECT_NAME}_lib_sources ./src/*.cpp)

# Removing the main.cpp from the sources of the library
list(REMOVE_ITEM ${PROJECT_NAME}_lib_sources main.cpp)¶

# Creating a new library for the project
add_library(${PROJECT_NAME}_lib ${${PROJECT_NAME}_lib_sources})

# Adding the include directories to the library
target_include_directories(${PROJECT_NAME}_lib PUBLIC ./include)

# Adding the main executable
add_executable(${PROJECT_NAME} ./src/main.cpp)

# Linking the project's lib to the project's executable (project's enrtry point)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_lib)

# Visiting the unittests' CMakeLists.txt
add_subdirectory(unittests)
