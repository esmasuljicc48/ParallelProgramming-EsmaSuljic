First I cloned the repo and copied the folder Example_3 into assignment3 folder of my repository. I first opened the make file and saw that the
target is commented out so I uncommented it and made the target my cpp file. After that I opened the cpp file. First I noticed 3 commented lines
so I uncommented them since they are in example 4 not commented. After that I noticed the comment saying to allocate array of SoA_type. So I
did like we did it in example 4 only instead of len/V I used num_blocks variable. After that I noticed the comment saying I need to deallocate the
resoruces but the way I wrote like we wrote on the lab creates the array on stack so I knew i had to make it on heap using new keyword so I did. 
After that the file looked okay so I ran the tests. The tests produced 5 .csv files. I moved the values to google sheets files and created a chart
but I was unable to create a chart like the one in example.
Here is the google sheets link: https://docs.google.com/spreadsheets/d/1nrRgEJmwH3xdy4tB-DQAf6TEFW4wq65cV9aW1TWhDjk/edit?pli=1&gid=0#gid=0
After that whats left is to push code to git and thats it.
As for analysis i noticed that with as N grows time grows the same way. Its linear. V has no consistent effect.
