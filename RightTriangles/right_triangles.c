//  main
//  Welcome to Right Triangles
//
//  Created by Nathanael Moody on 2/5/22.
//
//  This program was developed to calculate the third side of any given right-triangle 
//  once all data regarding side one and two are provided. As an added bonus, it is
//  able to provide the area and perimeter of the right-triangle, as well as providing 
//  the current date and time of which the program is being used. 

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h> 

extern double compute_area(double,double,double);

int main(int argc, char* argv[])
{
    double side1;
    double side1Square;
    double side2;
    double side2Square;
    double side3;
    double side3Square;
    double angle_degrees;
    double area_triangle;
    double sqrt(double side3Square);
    double P;


    // HEADER: Intro
    printf("\nWelcome to Right Triangles\n" );
    printf("This software was built by and maintained by Systems Programmer Nathanael Moody.\n\n" );


    // Printing the date and time.
    // printf("Today is January 28, 2022 at 9.43am.\n" );
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    int m;
    printf("Today is ");
    m = tm.tm_mon+1;
    switch(m)
    {
        case 1:
            printf("January ");
            break;
        case 2:
            printf("February ");
            break;
        case 3:
            printf("March ");
            break;
        case 4:
            printf("April ");
            break;
        case 5:
            printf("May ");
            break;
        case 6:
            printf("June ");
            break;
        case 7:
            printf("July ");
            break;
        case 8:
            printf("August ");
            break;
        case 9:
            printf("September ");
            break;
        case 10:
            printf("October ");
            break;
        case 11:
            printf("November ");
            break;
        case 12:
            printf("December ");
            break;
    }
     
    printf("%d,", tm.tm_mday);
    printf(" %d at ", tm.tm_year+1900);
    if(tm.tm_hour>=12)
    {
        if(tm.tm_hour==12)
            printf("12");
        else
            printf("%d", tm.tm_hour-12);
        printf(":%d pm.", tm.tm_min);
    }
    else
        printf("%d:%d am.", tm.tm_hour, tm.tm_min);



        printf("\n\nThis program will manage all of your right triangles.\n" );
        printf("Please enter the lengths of the two sides of the triangle forming a right angle.  Put white space between the two inputs and press enter after the second number.\n" );
        
        // Input for two sides of a right-triangle.
        // Input (Example): printf("13.5   16.9    <enter>\n" );
        scanf("%lf%lf",&side1,&side2);
        printf("\nYou entered %5.5lf and %5.5lf.\n\n",side1,side2 );

            angle_degrees = 90;
            area_triangle = (side1*side2) / 2;

            side1Square = (side1 * side1);
            side2Square = (side2 * side2);

            side3Square = (side1Square + side2Square);
            side3 = sqrt(side3Square);
            P = side1+side2+side3;

    // Triangle Area & Perimeter
    if ( (side1 > 0) && (side2 > 0) )
     {  
         printf("The area of this right triangle is "); 
         printf("%f", area_triangle);
         printf(" square units.\n" );

         printf("The perimeter of the same triangle is %f linear units.\n", P);   
         printf("Side 3 equals %f linear units.\n", side3);   
     
    }
    else
    {
        printf("Invalid data are among the inputs.  Please run this program again");
    }

    // Nanoseconds after Epoch
    printf("The time is now ");
    fprintf(stdout, "%.1f", (float)time(NULL));
    printf(" ns AE.\n" );

    // Footer: Outro
    printf("Have a nice day.\n" );
    printf("An integer 0 will be sent to the operating system as a signal of successful execution.  Bye.\n" );

    return 0;
}
