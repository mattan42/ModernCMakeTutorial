# Debugging CMake

CMake, as you probably know (or soon will), is a mini programming language. It has functions, macros, variables, can include other files and visit other files.

Often times we need some way to debug our CMake files, to see what which variable contains.

## Verbose Makefiles (and Verbose Build-Systems in General)

The best way to know what's going on is to look at the end results - the compiler run commands.

When using `Makefile`s, the way to make them verbose is to set the `CMAKE_VERBOSE_MAKEFILE` variable:

```cmake
set(CMAKE_VERBOSE_MAKEFILE ON)
```

In `Ninja`, it's as simple as running it with `--verbose`.

For other build systems, contanct the manual of that build-system to see how to enable "verbose" output.


## Printing directly from the CMake

In order to print values directly from the CMake file, we can utilize the `message()` function.

This command can be very complex if needed (as always, you're advised to look at the official documentation of the command for all the detail), but it can be as simple as:

```cmake
message(FATAL_ERROR "After printing this message, since it's a \"fatal error\", CMake would stop execution immediately")
```


## Watching Variables

The following command will run the given command when the given variable is changed:

```cmake
variable_watch(<variable> [<command>])
```


## Using a Proper Debugger

Since version 3.27, CMake supports debugging the `CMakeLists.txt` files using a debugger!

The debugger is a *quite powerful* tool in your disposal - it can show you exactly which targets you have, the content of their properties, the content of the global `CMAKE_*` properties.

And, as a debugger does, it allows you to debug the logic of your CMake files, whether it be functions or some `if()` statements.

### On VSCode

- Install the `vscode-cmake-tools` extension (which is a microsoft-developed extension, so you won't miss it on the extension store).
- Use the command `CMake: Configure with CMake Debugger` or [define the `launch.json` configurations](https://github.com/microsoft/vscode-cmake-tools/blob/main/docs/debug.md).
- Set your breakpoints and debug as you would a normal program.

