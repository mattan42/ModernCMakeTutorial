# Stage 5 - Solution

Here's a possible implementation:

- We would create a `TryCompileHeaders.cmake` file and create the functions there.

- Since we would like to work with targets (like every function in cmake works), we would create something like `target_try_compile_headers` which would accept a target.
    - We can even create a `targets_try_compile_headers` which would accept a list of targets.

- The function would go through all of the headers of the library, get their names, generate a `<header_name>.cpp` file that has only one line: `#include <header_name>.hpp`.

- We would creat a custom executable target for each such generated `.cpp` source file named `<main_target>_<header_name>_try_compile`

- This custom executable target would try compiling the target in the configuration stage, meaning that it won't actually try to build all these `_try_compile` executables when user calls the generated build system. It would already try to build these "targets" (see cmake's `custom_target` command) and verify there aren't any errors before generating the build-system.

- The command would either send a `message(FATAL_ERROR)` and fail evertying, or it would return (using a variable) a bool result to the user, and let the user decide what to do with the result.
