//  output_array.c
//  Management of Structs
//
//  Created by Nathanael Moody on 3/9/22.
//
//  Loop for outputting student information.

#include <stdio.h>
#include <string.h>
#include "student.h"

void display(struct student list[], int s);

void display(struct student list[], int s)
{
    int i;
    
    for (i = 0; i < s; i++)
    {

//  Here `printf` outputs the customer information.

        printf("\nAccount #: %i", list[s].customerID);
        getchar();

        printf("Customer name: %s", list[s].name);

        printf("Credit available:  %i", list[s].customerCredit);
        getchar();

        printf("Amount owed: %d", list[s].owedAmount);
        getchar();

    } 


}