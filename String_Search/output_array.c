//
//  output_array.c
//  String Search
//
//  Created by Nathanael Moody on 2/20/22.
//
#include <stdio.h>
#include <string.h>
#include "search.h"

int output_array(const char *myfile, const char *searchPatt) { // Definition
    int strLen  = strlen(myfile);  // Find length of string
    int wordLen = strlen(searchPatt);
    int matches = 0;

    for (int i = 0; i <= strLen - wordLen; i++) {
        // Match word at current position
        int found = 1;
        for (int k = 0; k < wordLen; k++) {
            // If word is not matched
            if (myfile[i + k] != searchPatt[k]) {
                found = 0;
                break;
            }
        }

        // If word have been found then print found message
        if (found != 0) {
            printf("%d\n", i);
            matches++;
        }
    }

    return matches;
}