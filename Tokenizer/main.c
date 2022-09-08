//
//  main.c
//  Tokenizer
//
//  Created by Nathanael Moody on 2/6/22.
//

#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char *filename;
    filename = (char *) malloc(100 * sizeof(char)); // Allocate space for the name of a file

    //HEADER: Intro
    printf("\nWelcome to Epic Software Systems, Inc. Head of Systems Lab: Nathanael Moody\n" );

    //Get File
    printf("Enter the name of a file to be tokanized: " );
    
    // Input ----------------------------------------------------------------

    scanf("%[^\n]", filename); // Read filename from user
        
        // Open File
          char *myfile = (char *) malloc(100 * sizeof(char)); // Allocate space for file contents
          FILE *specialdata = fopen(filename, "r"); // Open file for read operations
            int j = 0;
            int onebyte; // Used to move one byte from the file to the array

            // Reading -----------------------------------------------------------------

            while ((onebyte = fgetc(specialdata)) != EOF) { 
              //putchar(onebyte); // Just for us to see what's happening!
              myfile[j] = onebyte; // Copy the byte from the file into our array
              j++; // Update our 'j' counter
            }
                printf("%s", myfile);
                printf("\n%d", j);
                printf(" characters were read from the file into an array of the program.");

                // Tokenizing ---------------------------------

                //Input Token Separators
                    printf("\nThe tokenizing is ready to begin.\n" );
                    printf("Enter the separator characters which may include white space and press enter:" );
                             char* sep = (char*)malloc(20 * sizeof(char));
                            scanf("%s", sep);


                    printf("Confirmation: These are the separators => " );
                            printf("%s", sep);

                    printf("\nTokenizing has finished.\n" );

                    //Token List
                    printf("Here is the complete list of tokens:\n" );

                    int counter = 0;
                    char *tokens = strtok(myfile, sep);

                    //Token Print Loop
                    while (tokens != NULL)
                    {
                        printf( "Token number " );
                        printf( "%d", counter++);
                        printf( " is " );
                        printf("%s", tokens);
                        printf( "\n" );
                        tokens = strtok(NULL, sep);
                        
                    }

                    // Print all of our tokens which we just collected.
                        printf("\nTotal number of tokens is " );
                        printf("%d", counter);
                   
        fclose(specialdata);

    //Footer: Outro
    printf("\nHave a nice evening.\n" );
    return 0;
}