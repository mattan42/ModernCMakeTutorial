# Stage 4 - Debug and Release

> [!Warning]
> Linux and MacOS users should use `Makefile` or `Ninja` (and *not* ninja multi-config) in this stage.
> Windows users should not use MinGW but opt for using tools like WSL to run `make` or `ninja`.

## Introduction

In this stage, we'll take our solution from the previous stage and add `DEBUG` and `RELEASE` configurations.

## Steps

1. Read about how Debug and Release profiles work in CMake. Read about how single-configuration and multi-cofiguration build systems can affect the logic of the CMake file.

> [!INFO]
> In this stage, refrain from using multi-configuration build-systems (like `ninja-multiconfig`).

2. Create Debug and Release configurations for your project so that:
    - Compiling Debug will add `-g` flag to the compiler.
    - Compiling Release will add `-O3` flag to the compiler.

    Make sure that you can debug (with a debugger) both the executable and it's dependent libraries.

> [!INFO]
> In this stage, refrain from using `CACHE` variables in your `CMakeLists.txt` file.

> [!WARNING]
> Make sure you compile *all* the targets of the root project with the flags.

3. Create a custom profile `Warning` that compiles with `-Wall` flag.
