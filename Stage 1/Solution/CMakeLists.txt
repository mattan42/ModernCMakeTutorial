cmake_minimum_required(VERSION 3.28)
project(stage_1)

# Setting a cmake variable for convenienve.
set(MAIN_EXECUTABLE_SOURCES main.cpp)

# Adding the main executable with it's sources.
add_executable(main ${MAIN_EXECUTABLE_SOURCES})

# Doing the same for `another_main.cpp`
set(ANOTHER_MAIN_EXECUTABLE_SOURCES another_main.cpp)
add_executable(another_main ${ANOTHER_MAIN_EXECUTABLE_SOURCES})

# Adding the `DONT_PRINT_HELLO_WORLD` define only to another_main
target_compile_definitions(another_main PRIVATE DONT_PRINT_HELLO_WORLD)

