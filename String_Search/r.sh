#/bin/bash

#Program: String_Search
#Author: N. Moody

# First compile the c files into object files in any order, doesn't matter
gcc -m64 -Wall -Werror -o output_array.o -c output_array.c
gcc -m64 -Wall -Werror -o copyfile.o -c copyfile.c
gcc -m64 -Wall -Werror -o search.o -c search.c

# Now call the linker to link these obejct files into an executable file
gcc -m64 -Wall -Werror -o search.out output_array.o copyfile.o search.o

# Now execute the executable
./search.out
echo Goodbyte.



