# Stage 3 - Things Become More Real

## Initial Explanation

This is already getting close to a real project. In this stage we have:
- A header-only library, defining an interface.
- A library with an implementation to that interface.
- A main executable using the implementation.

Of course, the implemtation library and main executable have their corresponding unittests, and this time, they're compiled with googletest, so in actuality, we have 3 libraries and 1 executable.

## Instructions

- Don't edit any of the given files *unless* explicitly stated otherwise.
- Don't edit the folder structure.
- In this stage, you're given 1 existing `CMakeLists.txt` file.

## Steps

1. Read the `README`, header and source files of the libraries and executables. Understand whom should link to whom, who includes whom and so on. Get a grasp of the directory structure.

> [!NOTE]
> GoogleTest is not provided in repo, you need to bring it on your own.
> You can use [this documentation](https://google.github.io/googletest/quickstart-cmake.html) if you want to use CMake's `FetchContent` module or you can just `git clone` it on your own.

2. Create a `CMakeLists.txt` for `lib_music_player`. "Hint": It won't compile once you'll try to link it and include it in source files. There's a `;` missing!!
    - Find a "CMake"-like way to verify that the header file can be compiled; Without having to include it in a source file to force the compiler to try linking it.
    - After you do, you're welcome to fix the mistake and only that mistake!! Just add a `;` :)

3. Create a `CMakeLists.txt` file for `lib_spotify_player` and for the root project. Make sure you can compile:
    - Stage 3's executable
    - Stage 3's unittests
    - `lib_spotify_player`'s unittests.

> [!INFO]
> As you can see, the strategy used here to connect between libraries and executables is "git subtrees", which is somewhat similar to "git submodules".
> Even if you don't work with submodules, or subtrees, or both, breaking down the current problem will aid you in solving other CMake problems and give you a good idea of the different CMake mechanisms you can utilize to your advantage.

4. Look at `lib_spotify_player`'s given `CMakeLists.txt` file. Change the `set` of the variable `PLATFORM_HAS_BLUETOOTH` to `ON`:
```cmake
set(PLATFORM_HAS_BLUETOOTH ON)
```

- Make sure that after the change you can compile all the executables from the previous steps.

> [INFO!]
> For the sake of the tutorial we're just setting the value ourselves, but as you've seen until know, CMake is really powerful, and so on real projects (like spotify), there would probably be a real check here if the platform supports bluetooth (android? ios? mac? etc...)
