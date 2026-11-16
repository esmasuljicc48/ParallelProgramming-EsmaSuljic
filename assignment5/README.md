I have started by cloning the book repository and course repository. After that I ran different commands 
between different versions of timestep in the book repository and applied those chnages to my code (course 
reporisotry code). Running  make and then ./stream_triad we got the baseline:
timestep.c:9:22: missed: couldn't vectorize loop
timestep.c:9:22: missed: not vectorized: unsupported control flow in loop.
timestep.c:11:25: missed: statement clobbers memory: wavespeed_46 = sqrt (_8);
Minimum dt is 0.016964
Here we can see that the loop could not be vectorized. Now we were supposed to run likwid but 
I get an error saying that my processor is unsuported and 0 counters, it is because i use Virtual Box and it doesn't expose hardware performance, and I could not resolve it so 
I am unable to run those commands and didn't know how to make them work.
After that I edited the make file specifically the stream_triad line where instead of timestep I wrote 
timestep_opt1.o. ANd running make and ./stream_triad gave the following output:
timestep_opt1.c:9:13: optimized: loop vectorized using 32 byte vectors
timestep_opt1.c:11:9: missed: couldn't vectorize loop
timestep_opt1.c:11:9: missed: not vectorized: unsupported control flow in loop.
timestep_opt1.c:9:13: optimized: loop vectorized using 32 byte vectors
timestep_opt1.c:12:25: missed: statement clobbers memory: wavespeed_58 = sqrt (_26);
Minimum dt is 0.016964
Here we can see that the loop has been vectorized. But there is a line after it that says it could not 
vectorize it and to be honest I am not sure why it writes both so I did some research and from what I understand its because the compiler makes 2 copies of the loop and one gets vectorized thanks to
pragma but other one doesnt because it uses if statements combined with divison and sqrt, that can all cause errors and that copy is the scalar one.The copy with pragma also has the errors but it
tells the compiler to vectorize anyway and to ignore the erorrs. The vector lenght is 32 byte vector.
After doing all the same steps, for opt2 I got:
timestep_opt2.c:9:13: optimized: loop vectorized using 32 byte vectors
timestep_opt2.c:11:9: missed: couldn't vectorize loop
timestep_opt2.c:11:9: missed: not vectorized: unsupported control flow in loop.
timestep_opt2.c:9:13: optimized: loop vectorized using 32 byte vectors
timestep_opt2.c:12:25: missed: statement clobbers memory: wavespeed_58 = sqrt (_26);
Minimum dt is 0.016964
Same output as opt1. No additional explanations needed.
After doing all the same steps for opt3 I got:
timestep_opt3.c:8:13: optimized: loop vectorized using 32 byte vectors
timestep_opt3.c:10:9: missed: couldn't vectorize loop
timestep_opt3.c:10:9: missed: not vectorized: unsupported control flow in loop.
timestep_opt3.c:8:13: optimized: loop vectorized using 32 byte vectors
timestep_opt3.c:11:32: missed: statement clobbers memory: wavespeed_58 = sqrt (_26);
Minimum dt is 0.016964
Same output as opt1. No further explanation needed.
Now for otp3 with flags, I edited makefile and added the flags: -fno-trapping-math -fno-math-errno.
The output was:
timestep_opt3.c:8:13: optimized: loop vectorized using 32 byte vectors
timestep_opt3.c:10:9: optimized: loop vectorized using 32 byte vectors
timestep_opt3.c:8:13: optimized: loop vectorized using 32 byte vectors
Minimum dt is 0.016964
Now we can see that the loop has been vectorized because of the flags and all other errors are gone. And I think obviusly
this run is the best since we get vectorization and no errors.
