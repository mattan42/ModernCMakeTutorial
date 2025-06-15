# Stage 1

## Instructions

1. Read the [Initial Explanation](#initial-explanation) in this README file.
2. You are provided with some source files in the `Problem` directory. Don't modify them. You are free to create other files as you wish.
3. Follow the steps in the [objective](#objective) section.

## Initial Explanation

CMake is a build system generator, meaning that it generates build systems, like `Make` or `Ninja`.

As such tool, 2 steps are needed in order to compile a binary:
1. Generate the build system using the `cmake` command.
2. Compile the binary using the generated build system (If a `Makefile` was generated, then use `make`).

CMake uses a `CMakeLists.txt` file which contains all the logic CMake needs in order to generate a build-system for your project.

The most basic way to run CMake is:
```bash
cmake -Bbuild .
make -C build
```

This command tells cmake to generate the build system in the directory specified after `-B`. After that `.` tells CMake to look for the `CMakeLists.txt` file under the current directory (`.`).

The second command, `make` is using the Make build-system to compile your project.
`-C` just tells it to `cd` to the directory `build` before running `make`.

## Objective

1. Create a `CMakeLists.txt` file which compiles the `main.cpp` file.
2. Compile and run the `main.cpp` file. Make sure you can see the prints.
3. Compile the `main.cpp` file with the `DONT_PRINT_HELLO_WORLD` preprocessor define. Run it and make sure the print changes.
4. Compile at once both `main.cpp` and `another_main.cpp`; Don't have two separate `CMakeLists.txt` files for the executables and don't move the source files from the current directory structure.
5. Add the `DONT_PRINT_HELLO_WORLD` ONLY to `another_main.cpp`. Compile and run both executables and see that `main.cpp` prints "Hello World" normally and that `another_main.cpp` prints an additional initial print.
6. Keep your `CMakeLists.txt` file you've written until this step. Find a way to compile only one binary.
