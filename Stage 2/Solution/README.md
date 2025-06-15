# Stage 2 - Unittests - Solution

> [!NOTE]
> To try out the solution yourself, copy the `CMakeLists.txt` files to the appropriate directories in the `Problem` directory.

## 1. Read about `add_subdirectory()` and `add_library()` commands in CMake and think about how you can utilize them to create a more modular CMake generation.

The `add_subdirectory()` command visits a subdirectory and searches it for a `CMakeLists.txt` file, which it then runs recursively. It is treated as a "child" CMake file (the first cmake being called is called the "root" CMake), which has several implications that will be discussed later.

The `add_library()` command adds a target library, similarly to the way `add_executable()` adds an executable target.

## 2. Add a root `CMakeLists.txt` file, compile with it the project.

This step can be done almost in the same way as in Stage 1. The addition here is the usage of `target_include_directories()` to be able to import the `music_player.hpp` header.

The real problem arises when trying to compile the unittests.

The unittests need the exact same sources as the "main executable", just without the main, yet they're two different targets (two different executables).

The immediate solution to this problem is to create two executables and give them the same sources with the exception of a different `main.cpp` file.

This approach can be a bit tedious - it requires us to manage two targets and do our best to make them the *exact* same (since we want the unittests to test the main executable's components as reliably as we can). You can already imagine such approach will requrie *a lot* of code duplication. Every `target_compile_definitions`, or `target_compile_options` will be written twice - once for the unittests executable and once for the main executable.

The solution illustrated in the `CMakeLists` manages even more targets, but, it is less tedious and bug-prone (explained in the next step).


## 3. Add a `CMakeLists.txt` file for the unittests.

In this step all of the knowledge we've learned is used to create an ideal solution.

First, we would create a library target which will contain all of the sources of our project *without* our main.

We've used `file(GLOB_RECURSE)` command in order to collect the sources recursively using glob syntax, and used the `list()` command in order to remove the `main.cpp` source from the found list of sources.

> [!NOTE]
> CMake's official documentation encourages against using `GLOB_RECURSE`. Do read [their explanation here](https://cmake.org/cmake/help/latest/command/file.html#filesystem). Personally, I don't think the alternatives worth the re-generation of the build-system that much. If you want to expand your knowledge even further, read the [Alternative to Glob Recurse](../../Appendix/Alternative%20to%20Glob%20Recurse.md) under the appendix.

We use `target_include_directories()` to attach our headers to the library target (compile-wise, the directories we give in this command will be added to the compilation command with the `-I` flag).

In this line, the `PRIVATE` / `PUBLIC` scope becomes very relevant. If we include our `include` directory with `PRIVATE`, the linked targets won't inherit these include directories and would not be able to find the "music_player.hpp" header.

Most of the times, in the cases of libraries, we would want the headers to be included to the library target with a `PUBLIC` scope keyword, so that the using target would be able to get the include directories "out of the box".

Notice that now, when we create our main executable (with just the `main.cpp` source) and link it to the project's library (`target_link_libraries()`), we don't have to include the `./include` directory again - it is inherited automatically from the project's library.

> [!NOTE]
> This feature of CMake will become even more useful in later. Make sure you understand it!

After that, we include the subdirectory `./unittests`. CMake then will continue to go through that directory's `CMakeLists.txt` file.

In the unittests' `CMakeLists.txt` file, we do the exact same - create an executable (this time with the unittests' `main.cpp`) and link it to the project's library.

> [!NOTE]
> Since this is a "child" `CMakeLists.txt`, it "inherits" the targets that were created before it (both from the root cmake and **from other child cmake files too!**), so we can just assume this target was created and link against.

## 4. Compile both the project's executable and the unittests' executable using `make -C build`.

This step just forces us to use `add_subdirectory()`. If the compilation of the unittests and the main project are two different `CMakeLists.txt` files that don't have any connections, we would have to run `cmake` twice (on each directory).

# Key Points

Whoa! Long explanation and defenitly not an easy stage.

The key points to take from this stage are:

- How multiple targets can help us manage a modular and less bug-prone CMake environment.
- How we can utilize `add_subdirectory` to create more modular CMake environments, without having all the logic cramped into one `CMakeLists.txt` file.
- How the `PRIVATE` and `PUBLIC` scope keywords matter when linking against different targets.

