//
//  copyfile.c
//  String Search
//
//  Created by Nathanael Moody on 2/20/22.
//
#include <stdio.h>
#include <stdlib.h>
#include "search.h"

char *copyfile(const char *filename) {
    FILE *specialdata = fopen(filename, "r"); // Open file for read operations
    char *myfile;
    int size = 0;

    if (specialdata == NULL)
        return NULL;

    while (fgetc(specialdata) != EOF) {
        size++;
    }
    myfile = malloc(size + 1); // Allocate space for file contents
    if (myfile != NULL) {
        rewind(specialdata);
        for (int i = 0; i < size; i++) {
            myfile[i] = fgetc(specialdata);
        }
        myfile[size] = '\0';  // null terminate the string
    }
    fclose(specialdata);
    return myfile;
}