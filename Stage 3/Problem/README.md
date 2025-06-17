# Stage 3 - Things Become More Real

## Initial Explanation

This is already getting close to a real project. In this stage we have:
- A header-only library, defining an interface.
- A library with an implementation to that interface.
- A main executable using the implementation.

Of course, the implemtation library and main executable have their corresponding unittests, and this time, they're compiled with googletest, so in actuality, we have 3 libraries and 1 executable.

## Steps

1. Read the `README`, header and source files of the libraries and executables. Understand whom should link to whom, who includes whom and so on. Get a grasp of the directory structure.

> [!NOTE]
> GoogleTest is not provided in repo, you need to bring it on your own.
> You can use [this documentation](https://google.github.io/googletest/quickstart-cmake.html) if you want to use CMake's `FetchContent` module or you can just `git clone` it on your own.

2. Create a `CMakeLists.txt` for `lib_music_player`. "Hint": It won't compile once you'll try to link it and include it in source files. There's a `;` missing!!
    - Find a "CMake"-like way to verify that the header file can be compiled; Without having to include it in a source file to force the compiler to try linking it.
    - After you do, you're welcome to fix the mistake and only that mistake!! Just add a `;` :)

3. Create a `CMakeLists.txt` file for each different component. Make sure that the following requirements are answered:
    - You can compile the library and unittests of `lib_spotify_player` individually (run `cmake` from the `lib_spotify_player` directory)
    - You can compile Stage 3's executable, it's unittests *and* `lib_spotify_player`'s unittests (from Stage 3's Problem directory).

