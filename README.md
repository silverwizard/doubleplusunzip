doubleplusunzip
===============

The Worlds First File Inflater

To build:
`make`

OR if you want to *install* it you can run:
`make install`

My further work will to be to properly use getopt (like not a chump), and also to create a proper useage()

Right now, just use:
`dpu [decompression size] filename`

The decompression size is an optional argument, and when used it will multiply the filesize by that. The default amount is 10 (making a file 10 times bigger).

The output of the program will the filename.dpu
