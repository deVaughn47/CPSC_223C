//
//  main
//  search.c
//  String Search
//
//  Created by Nathanael Moody on 2/20/22.
//

#include <stdio.h>
#include <stdlib.h>
#include "search.h"

int main(int argc, char *argv[]) {
    char filename[1000];
    char searchPatt[1000];

    printf("\n\nWelcome to 'Find Your Match' produced by Orange Blossom Lucky Software, Inc.\n");
    printf("Project leader: Nathanael Moody\n");
    printf("This program will find the matching strings in any file.\n");

    printf("\nPlease enter the name of the file to be searched: ");
    if (scanf("%999[^\n]", filename) != 1) { // Read filename from user
        fprintf(stderr, "Invalid or missing input\n");
        return 1;
    }
    printf("Thank you. You entered %s\n\n", filename);

    // load the file
    char *myfile = copyfile(filename);
    if (myfile == NULL) {
        fprintf(stderr, "Cannot load file %s\n", filename);
        return 1;
    }

    printf("Please enter the search pattern you are seeking: ");
    if (scanf("%999s", searchPatt) != 1) { // Read search pattern you are seeking
        fprintf(stderr, "Invalid or missing input\n");
        return 1;
    }
    printf("Thank you. You entered: %s.\n", searchPatt);

    printf("\nThe search key, %s, is found in these positions within the file:\n", searchPatt);

    int matches = output_array(myfile, searchPatt);

    printf("\nNumber of matches: %d\n", matches);
    free(myfile);

    printf("This completes the string search. Please enjoy your matches.\n");
    printf("A zero will be returned to the operating system.\n");
    printf("Bye.\n");

    return 0;
}
