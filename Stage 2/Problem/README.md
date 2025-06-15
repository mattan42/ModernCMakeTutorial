# Stage 2 - Unittests

## Initial Explanation

In this stage we have a rather standard directory structure of an executable project:
- A `src` dir containing all the sources of the project.
- An `include` dir containing all the headers of the project.
- A `unittests` dir containing the unittests of the project.

In this stage, we want to be able to compile 2 targets:
1. Our project's executable.
2. Our project's unittests executable.

> [!NOTE]
> This stage has a `Hints` directory with hints for each step. If you find yourself a bit stuck on what to do - don't hesitate to take a look there!

## Objective Steps

1. Read about `add_subdirectory()` and `add_library()` commands in CMake and think about how you can utilize them to create a more modular CMake generation.
2. Add a root `CMakeLists.txt` file, compile with it the project.
3. Add a `CMakeLists.txt` file for the unittests.
4. Compile both the project's executable and the unittests' executable using:

```bash
cmake -Bbuild .
make -C build
```
