# Stage 5 - Bonus Stage!


## Introdution

This stage is a "bonus" stage, in which you'll try creating a CMake module, include it and use it.

This stage doesn't have a proper written "solution" because implementations may vary. Instead, it has an idea of implementation as a solution. If you get stuck, you can take a look at it and decide if you want to use the implementation or make one yourself.

## Problem

Look at the `lib_music_player` from stage 3. This library is just one header, it's an `INTERFACE` library; it doesn't have soruces.

However, what if there is a syntax mistake in the header? We would only notice it once we include it in an actual source file and let the compiler try processing the header.

Wouldn't it be nice if there was a CMake module we could `include()`, give it our header file, and it would verify if it can be compiled successfully?

Try creating such module. You're free to create the `api` however you want and implement it however you think you can!
