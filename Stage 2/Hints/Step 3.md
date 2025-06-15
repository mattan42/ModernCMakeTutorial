# Stage 2 Step 3 Hint

This is the hardest stage, do your best!

- Think about how `add_subdirectory()` and `add_library()` can help here.

- Note that in child `CMakeLists.txt` you can use targets from the root `CMakeLists.txt`; You can define a library in the root CMake, assume it was created and use it in the child CMake.

- Think about what problems arise from trying to compile both a main executable and a unittests executable using the same sources and headers except...? What can you do about it?