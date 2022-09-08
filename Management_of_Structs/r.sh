#/bin/bash

#Program: Management of Structs
#Author: N. Moody

# First compile the c files into object files in any order, doesn't matter
gcc -m64 -Wall -Werror -o output_array.o -c output_array.c
gcc -m64 -Wall -Werror -o fillarray.o -c fillarray.c
gcc -m64 -Wall -Werror -o bubble_sort.o -c bubble_sort.c
gcc -m64 -Wall -Werror -o academic.o -c academic.c

# Now call the linker to link these obejct files into an executable file
gcc -m64 -Wall -Werror -o academic.out output_array.o fillarray.o bubble_sort.o academic.o

# Now execute the executable
./academic.out



