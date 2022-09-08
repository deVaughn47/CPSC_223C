//  main
//  academic.c
//  Management of Structs
//
//  Created by Nathanael Moody on 3/9/22.
//
//  This program was developed to manage all student records provided
//  by the user. Sorting by student ID, the user must provide the names,
//  ID numbers, major and zip code of all students to be recorded. Once
//  all the desired information is provided, the program will sort and 
//  output the recorded student records in ascending order.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "student.h"

//  Function calls for inputting, sorting and displaying student information.
void accept(struct student list[], int s);
void display(struct student list[], int s);
void bsortDesc(struct student list[], int s);

int main()
{

//  Declairation of 'student data[]' struct array, 'n' counter for "number of records input",
//  and 'moreData' bool working in tandom with characters 'Y' and 'N' to determine
//  if more information needs to be input.
    struct student data[20];
    int n;
    char Y;
    Y = 1;
    char N;
    N = 0;
    int i;
    n = 0;
    char moreData;
    moreData = N;
    moreData = Y;
    
    printf("\n\nWelcome to Academic Records.\n");


    printf("\nPlease enter the data one student at a time.\n\n");

    
//  This 'for' loop is set equal to the number of records input by the user.
    for (i = 0; i <= n; i++)
    {
        accept(data, n);

            printf("\nDo you have more data (Y or N)?\n");
            fgets(&moreData, 2, stdin);
            getchar();

            if (moreData != 'Y')
            {
                break;
            }
            else
            {
                n++;
            }
        
    }

//  This initialization of 'n = n + 1' creates a buffer to ensure enough
//  space is allocated for the desired stuent information to be recorded.
    n += 1;


//  Output of student information before and after it has been sorted.
    printf("\nThank you. Here are the data you entered:\n");
    display(data, n);

    printf("\n\nThe student data will next be sorted.");
    bsortDesc(data, n);

    printf("\nThe list of student data is now ordered as follows.\n");
    display(data, n);

    printf("\n\nThank you for using this sorting program.\n");
    printf("The number of students in the array will be returned to the main function.\n");
    printf("Main received this number %d and will keep it. A zero will be returned to the operating system.\n", n);
    printf("Bye.\n\n");

    return 0;
} 
