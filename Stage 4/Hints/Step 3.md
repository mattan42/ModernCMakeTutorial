# Stage 4 Step 3 Hint

Try `rm -r` your build directory and run with your desired profile. Now it works, right?
Why is that that when we delete the build directory and configure from scratch it works, but when we run with one profile and call cmake on the same build directory with other profile it doesn't?

Try reading about `CMakeCache.txt`.
