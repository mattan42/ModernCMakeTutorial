# Stage 1 Solution

1. Create a `CMakeLists.txt` file which compiles the `main.cpp` file.

Several basic things are needed to be in the `CMakeLists.txt` file:
- `cmake_minimum_required` specifies which is the minimum version of `cmake` needed to use this `CMakeLists.txt` file.
- The `project()` function specifies the name of the cmake project.
- The `add_executable` adds an "executable target", as well as specifying it's sources.

> [!NOTE]
> Even without the variable (`add_executable(main main.cpp)`) the function will still work the same.

2. Compile and run the `main.cpp` file. Make sure you can see the prints.

From the `Problem` directory, we need to run:
```bash
cmake -Bbuild . && make -C build # to build
./build/main # To run
```

3. Compile the `main.cpp` file with the `DONT_PRINT_HELLO_WORLD` preprocessor define. Run it and make sure the print changes.

For this we need to add the define to our exeutable's compilation. There are two convenient functions to do this: `add_compile_definitions()` and `target_compile_definitions()`, from which the latter is prefered.

`add_compile_definitions()` adds the compile definitions for *all* targets built by the cmake file (and it's children).

This is dangerous, because it requires us to be sure we want to add the compile definitions to *all* targets. Even if we're sure that all targets should contain this compile definitions, are future targets supposed to have this definition too?

This approach, while can be more "convinient" than the latter approach, can be bug prone.

`target_compile_definitions()` adds the compile definitions *only* for the specified target, with the addition of a "scope" parameter (`PUBLIC` / `PRIVATE`). We will get into the different scopes effect in a later stage, but the important take is that this command gives us way more control of the compile definition than `add_compile_definitions()`.

4. Compile at once both `main.cpp` and `another_main.cpp`; Don't have two separate `CMakeLists.txt` files for the executables and don't move the source files from the current directory structure.

This requires us to add another `add_executable()` command. In other words, add another target, with it's own sources.

After running the `cmake` and `make` commands, you should be able to see both of your executables compiled.

5. Add the `DONT_PRINT_HELLO_WORLD` ONLY to `another_main.cpp`. Compile and run both executables and see that `main.cpp` prints "Hello World" normally and that `another_main.cpp` prints an additional initial print.

If you've used the `add_compile_definitions()` in the previous step, you're limited - both of the targets get the definition even tough we want only one of them to compile with the definitions.

If you've used `target_compile_definitions()` then this step is trivial - hand over the definition only to the desired target.

6. Keep your `CMakeLists.txt` file you've written until this step. Find a way to compile only one binary.

This step requires specifying to `make` which target you want to build:

```bash
cmake -Bbuild . && make -C build main
```

This step illustrates the direct connection between the "cmake" targets to the targets of the generated Make build system.

In a nutshell (since this isn't a "Makefiles" tutorial), when you run `make`, all targets defined in the Makefile will be built. However, you can define exactly which target you want to build, and so make will build only that target.

> [!NOTE]
> While now this doesn't seem too useful now, it'll become quite useful in later stages.

