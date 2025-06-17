cmake_minimum_required(VERSION 3.28)

# We will use it later
set(PARENT_PROJECT_NAME ${PROJECT_NAME})

# The PROJECT_NAME variable will be populated with the last caller to `project()` command.
# So this will result in "stage_2_unittests"
project(${PARENT_PROJECT_NAME}_unittests)

# Adding the unittests executable with it's sources
add_executable(${PROJECT_NAME} EXCLUDE_FROM_ALL ./main.cpp)

# Linking to the project's library
target_link_libraries(${PROJECT_NAME} PRIVATE ${PARENT_PROJECT_NAME}_lib)

