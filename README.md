doubleplusunzip
===============

The Worlds First File Inflater

Installation is simple, I don't feel the need for a makefile, but if you've no idea how to compile, just run:

cc -o dpu ./dpu.c
cc -o undpu ./undpu.c

OR if you want to *install* it you can run:

cc -o /usr/local/bin/dpu ./dpu.c
cc -o /usr/local/bin/undpu ./undpu.c

My further work will to be to properly use getopt (like not a chump), and also to create a proper useage()

Right now, just use:
dpu [decompression size] filename

The decompression size is an optional argument, and when used it will multiply the filesize by that. The default amount is 10 (making a file 10 times bigger).

The output of the program will the filename.dpu
