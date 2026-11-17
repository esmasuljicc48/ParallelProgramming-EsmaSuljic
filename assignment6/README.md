I have started by pulling from course repository and cloning chapter7 repository. I took all the files in example6 of week7 of course repository and took 2 files from chapter7 repository the stencil_opt4 and 6. After that
I edited the makefile. To the SOURCES I added the other 2 files we will test. Added 2 more run targets the same way the target for opt2 already existed. At the end I edited the cleanup where I added
opt4 and 6.Results: 
[Results](results.txt)
[Picture](Pasted image.png)
Difference between version 2 and 4 is that in version 4 we use one parallel region. In opt4 the threads are created once and stay alive for all 10,000 iterations,each tread computes only its own part
because of the #pragma omp for. In opt2 they’re created and destroyed twice per iteration (20,000 times).In opt4 printing, pointer swapping and the timers must happen once so theyre in the if 
condition and they are only run by thread 0. And if all threads ran the timer they could overwrite eachother so only thread 0 does it. In opt2 this wasnt an issue because those lines for printing,
swapping and timer are outside the parallel region where there is only one thread.
Then we have omp for nowait on the flush loop, omp for lets the existing threads split the loop, and nowait means they don’t wait for each other. But opt4 has an issue because there is no barrier
after the swap and so other threads could start the next step before thread 0 finishes swapping. It  works because the flush takes longer than the swap. opt6 fixes this by adding a barrier after
the swap, it also uses pragma omp parallel before the initialization meaning threads get created only once and there is one start and one end. THere is also no omp for to divide rows but the code 
divides it at the start. So opt6 is the best design.

My PC (VM) used 4 threads as seen on the picture.
