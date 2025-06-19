# Stage 3 - Solution

## 1. Read the `README`, header and source files of the libraries.

The main project is a multi-source music player - it can play music from different sources (Spotify, Apple Music, Local Files, etc..), even though it only supports Spotify currently.

It uses the generic interface `MusicPlayer` from the library `music_player`.

It also uses the Spotify implementation of the `MusicPlayer` interface from the `spotify_player` library.

Using these two it creates a decorator `MultiMusicPlayer` which can use different sources to play music.

The `spotify_player` can have a `bluetooth` feature depending if the platform has bluetooth.

This feature, if enabled, defines a define which the main executable also uses.

## 2. Create the CMake files

This step is more or less the same as the previous step - we create a library target and link other targets (libraries and executables) to other targets.

This is the core of modern CMake.

A few changes need to be noticed here:

### Lib `music_player`

This library is only one header and has no sources, and so we need to define it using the `INTERFACE` keyword.


### Lib `spotify_player`

This library has unittests of itself, which creates a problem:

On the one hand, we want to compile the unittests when we used as a library - if the main project uses defines and / or compile features we might not have anticipated when writing the library, we would catch them only when compiling the unittests with the configurations of the main project.

On the other hand, we do want to compile the unittest independantly of a root project. We want to compile the unittests if we are, as the library, the root project.

However, in both cases, the way we include the `music_player` lib differ.
In the first case, we already have the `music_player` target created for us by the root project. In the second case, we need to create our own solution for importing the `music_player` library.

While a solution isn't provided for *how* to include the `music_player` library for the second case (in which the library *is* the root project), the solution shows an `if` statement inside which a solution can be implemented.

### Root Project Unittests

The unittests use GoogleTest, which isn't provided "out-of-the-box" in this repository.

In this solution, we've used the `FetchContent` cmake module, which fetches the googletest source from a URL and visits it's cmake file, making it ready for usage.

Another solution is to manually git cloned the googletest git repository and `add_subdirectory` to it.

> [!INFO]
> In general, CMake provides a lot of ways to achieve the same goal, with each solution having it's benefits and disadvantages. It's up to you to understand CMake and choose the best solution for you.

## 3. The `PLATFORM_HAS_BLUETOOTH` Compile Definition

After changing the variable `set(PLATFORM_HAS_BLUETOOTH ON)`, we need to actually set the compile definition of the library:

```cmake
set(PLATFORM_HAS_BLUETOOTH ON)
if(PLATFORM_HAS_BLUETOOTH)
    # We want to add the bluetooth feature to our spotify player here!
    target_compile_definitions(spotify_player PUBLIC SPOTIFY_ENABLE_BLUETOOTH)
endif()
```

The important thing to notice here is the `PUBLIC` scope keyword. If this scope keyword is used, each target that links against this target will inherit this compile defition, and thus can use it.

You can see how the main executable's library and unittests use the compile definitions in order to test things and use features correctly.

> [!INFO]
> Besides the usefulness of this CMake feature, we can observe that a real usage of `PLATFORM_HAS_BLUETOOTH` doesn't have to be simple and trivial like setting a vairbale on / off.
> Instead, we could write our own function which identifies to which platform we're trying to compile the library to and determines if this platform supports bluetooth or not.


# Imoprtant Points

- Libraries which only have headers must be defines using the `INTERFACE` keyword.
- Libraries should be somewhat aware of how they're includig their dependencies - are they getting them from a parent root CMake project, or should they get them themselves?
    - This can get even more advanced - do they need to get the sources and compile their dependencies themselves? Do they accept pre-compiled binaries?
- `FetchContent` is one solution of importing dependencies using a CMake module.
- The `PUBLIC` scope keyword can be vital for compile definitions and for other target properties we want the linked targets to inherit.
- CMake can run external checks and logic to determine important things for the compilation processs (like in this example, if the target platform has bluetooth or not).
