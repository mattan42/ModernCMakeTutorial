# Alternative to Glob Recurse

> [!NOTE]
> This problem is encountered at [Stage 2](../Stage%202/).

CMake's official documentation [advises against using `GLOB_RECURSE`](https://cmake.org/cmake/help/latest/command/file.html#filesystem).

While I do personally think that the advantages (of globbing) outweight the disadvantages, these are some of the alternatives:

## Specify Each File Manually

Yes, it is possible to just manually write each of the sources in the `CMakeLists.txt`:

```cmake
set(sources
    ./src/music_player.cpp
    ./src/spotify_player.cpp
    ./src/apple_music_player.cpp
    ./src/youtube_music_player.cpp
    ...
)
```

While it's annoying, it's not a bad solution at all. Forgetting to add a source without noticing is not a realistic scenario (as long as you have unittests, of course).

## Having a Script to Generate Source List

Some people are doing things like:

```cmake
set(SRC_FILES "")

# [[[cog
#    import cog, glob
#    for src in glob.glob('*.cpp'):
#       if "skeleton" in src: continue
#       cog.outl("SET(SRC_FILES ${SRC_FILES} %s)" % src)
# ]]]
# [[[end]]]

add_library(mylib STATIC  ${SRC_FILES})
```

And then running `python -m cogapp -r CMakeLists.txt` to generate their `CMakeLists.txt`.

This solution can be a bit modular if we generate the source files to a `.cmake` file and `include()` it in the needed `CMakeLists.txt` file (and then we only generate a relatively small thing using code and don't have to generate all our main `CMakeLists.txt` file)

However, this can cause the same problem as the previous solution (forgetting to specify a source file), and may even be more troublesome if there's a bug in the script.

## Modular Approach Using Subdirectories

Another approach is to utilize the `target_sources()` command which adds sources to a target.

Since the target doesn't have to be created in the same CMake file (as long as it was created in a parent cmake file), we can assume the target we need and add the sources in the directory we're present in.

### Example

```
├── CMakeLists.txt
├── src_1
│   ├── CMakeLists.txt
│   ├── hi2.cpp
│   └── hi.cpp
└── src_2
    ├── bye.cpp
    └── CMakeLists.txt
```

`./CMakeLists.txt`:
```cmake
add_library(project_lib)
```

`./src_1/CMakeLists.txt`:
```cmake
target_sources(project_lib PRIVATE
    ./hi.cpp
    ./hi2.cpp)
```

`./src_2/CMakeLists.txt`:
```cmake
target_sources(project_lib PRIVATE
    ./byte.cpp)
```
