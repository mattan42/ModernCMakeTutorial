# Stage 4 - Solution

## 1. How Build Profiles Work in CMake

CMake has kind of a weird but nice way of allowing to create different build types.

Theres the `CMAKE_BUILD_TYPE` variable that the user can specify when calling `cmake`:

```bash
cmake -Bbuild -DCMAKE_BUILD_TYPE=DEBUG .
```

This `CMAKE_BUILD_TYPE` contains a string with the name of the `CONFIG`. CMake then automatically tries using the following variables:
- `CMAKE_<LANG>_FLAGS_<CONFIG>`
- `CMAKE_<TARGETTYPE>_LINKER_FLAGS_<CONFIG>`

> [!Info]
> Note that you don't need to do an `if (CMAKE_BUILD_TYPE STREQUL DEBUG)` to verify on which build-type you are - CMake already automaticallyl does that and takes the appropriate variables based on the `<LANG>` and `<CONFIG>`(=`CMAKE_BUILD_TYEP`) values it has received from the user.

So, in order to set debug flags for C++ targets, we would do:

```cmake
set(CMAKE_CXX_FLAGS_DEBUG "-g")
```

However, this will override any previously defined debug flags. The `CMAKE_<LANG>_FLAGS_<CONFIG>` variable is not a list but a string, so in order to append to that string, we would do:

```cmake
set(CMAKE_CXX_FLAGS_DEBUG "-g ${CMAKE_CXX_FLAGS_DEBUG}")
```

(kind of like we do with the `$PATH` env variable in our `zshrc`/`bashrc` files)

However, all of this is true for single configuration build-systems like `make` or `ninja`.

Multi-configuration build-systems are a bit harder to configure and require using "generator-expressions", a concept we won't get into in this tutorial.


## 2. Create Debug and Release Configurations

In this step we implement the knowledge we've gained in the previous step.

According to CMake's documentation:

> Multi-config generators use CMAKE_CONFIGURATION_TYPES as the set of configurations and ignore CMAKE_BUILD_TYPE.

So first of all, we need to prevent the user from trying to use our CMake file to generate multi-config build-systems.

For that, we use the `GENERATOR_IS_MULTI_CONFIG` variable.

From CMake's Docs:
> Read-only property that is true on multi-configuration generators.
> 
> True when using a multi-configuration generator such as:
> - Ninja Multi-Config
> - Visual Studio Generators
> - Xcode

After that, we want to force the user to choose a valid configuration. This is optional but recommended.

Then we set the appropriate variables with the appropriate flags we want to include when building for each profile, using the `set()` command.

As you can see from the `Makefile`, we call CMake each time with a different build dir per different profile. This is because we work with single-configuration build-systems. Meaning that after we've called cmake, it has generated us a build-system that can build only for one configuration.

In order to avoid mistakes and bugs from re-configuring the cmake, we can spare ourselves a lot of headache and just create different directories per different configuration.

> [!INFO]
> For more on that, you can read the appendix regarding cache variables and multi-config build systems.

## 3. Create a Custom Profile `Warning`

For this stage, we specify our configurations for the profile `Warning` exactly like we've specified for `Debug` and `Release`.
