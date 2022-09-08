//  bubble_sort.c
//  Management of Structs
//
//  Created by Nathanael Moody on 3/9/22.
//
//  Sorting by student ID in ascending order.

#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void bsortDesc(struct student list[], int s);

void bsortDesc(struct student list[], int s)
{
    int i, j;
    struct student temp;
    
    for (i = 0; i < s - 1; i++)
    {
        for (j = 0; j < (s - 1 - i); j++)
        {
//  Simple sort loop, using `temp` as a placeholder.
            if (list[j].studentId > list[j + 1].studentId)
            {
                temp = list[j + 1];
                list[j + 1] = list[j];
                list[j] = temp;
            } 
        }
    }
}