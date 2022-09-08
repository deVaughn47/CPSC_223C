//  fillarray.c
//  Management of Structs
//
//  Created by Nathanael Moody on 3/9/22.
//
//  Input code for collecting student information.

#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void accept(struct student list[], int s);



void accept(struct student list[], int s)
{

//  Input prompts for student Name, ID, Major, Class Level and Zip info.
        printf("\n\nEnter data for Record #%d", s + 1);
        
        printf("\nName: ");
        fgets(list[s].name, 50, stdin);

        printf("CWID: ");
        scanf("%d", &list[s].studentId);
        getchar();

        printf("Major: ");
        fgets(list[s].major, 50, stdin);

        printf("Class level (fresh=0,soph=1,junior=2,senior=3): ");
        scanf("%ud", &list[s].level);
        getchar();

        printf("Zip: ");
        scanf("%d", &list[s].zip);
        getchar();

}
