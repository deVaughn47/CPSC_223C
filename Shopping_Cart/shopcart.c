//  shopcart.c
//  Shopping Cart
//
//  Created by Nathanael Moody on 3/23/22.
//pragma GCC diagnostic ignored "-Wformat-truncation"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define filenametemplate "receipt%d.txt"

void displayProduct();
void purchaseProduct();
void repeatMenu();
void viewShopcaart();

FILE *inventoryFile;
FILE *receptFile;
char filename[100];
char fileName[100] = "receipt.txt";
size_t i;
char * location;
char menuSelect, c;

int main()
{
    // Open new 'receipt.txt' file
    FILE *receptFile;
    int makeFile = 2;  
    receptFile = fopen("receipt.txt", "r");
    while (receptFile != NULL)
    {
        for ( i = 1; i < makeFile; i++)
        {   
            makeFile++; // Incrementing 'int makeFile' allows for infinite receipt production
            if (receptFile != NULL)
            {
            fclose(receptFile);
            int num = i; //This is the number to be added to the file name 
            sprintf(fileName, filenametemplate, num);

            receptFile = fopen(fileName, "r");
            }
            else
            {
                break;
            }
        }
    }

    printf("\n\nWelcome to Golden State Emporium.\n");

    printf("\nHere is our menu:\n\n");
    printf("    D = Display list of merchandise in current inventory\n");
    printf("    P = Purchase an item\n");
    printf("    R = Repeat this menu\n");
    printf("    V = View shopping cart\n");
    printf("    X = Exit, compute amount due, generate receipt.\n");

// Menu selection
    while( toupper(menuSelect) != 'X')
    { 
        printf("\n\nPlease enter menu section: ");
        scanf(" %s", &menuSelect); // note leading blank in format string; this tells scanf
                     // to skip any leading whitespace characters.

            switch(toupper(menuSelect))
            {
                case 'D': displayProduct();
                       break;
                case 'P': purchaseProduct();
                       break;
                case 'R': repeatMenu();
                       break;
                case 'V': viewShopcaart();
                       break;
                case 'X': 
                       break;
                default:  printf("Sorry. That item is out of stock.\n");
                       break;

            }
    }

// Outro
    printf("    Your receipt is being generated.\n");
    printf("    Please view your receipt in the file: %s\n", fileName);
    printf("Thank you for shopping at our store.  Bye\n");
    fclose(receptFile);

    return 0;
} 

void displayProduct()
{   
    FILE *inventoryFile;
// Open 'inventory' file
    char filename[100] = "inventory.txt";
    inventoryFile = fopen(filename, "r");
    if (inventoryFile == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
    
// Read contents from file
    c = fgetc(inventoryFile);
    printf("\n");
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(inventoryFile);
    }
    printf("\n");
    fclose(inventoryFile);
}

void purchaseProduct()
{   
    FILE *inventoryFile;
    FILE *receptFile;
    int stock = 0; // Check how many times item was found successfully.
    char line[97];
    char itemWanted[64];
    char * location;
    double item_invent;
    float total; 
    char filename[100] = "inventory.txt", c;
    inventoryFile = fopen(filename, "r");

// Input item name
    printf("Enter name of item wanted.  Must match on first 8 characters: \n");
    fgetc(stdin);
    fgets(itemWanted, 100, stdin);
    itemWanted[strlen(itemWanted) - 1] = '\0';
    strncmp(itemWanted, filename, 8);

    while (fgets(line , sizeof(line) , inventoryFile ) != NULL)
    {
        if (strstr(line , itemWanted )!= NULL)
        {
            stock++;
            size_t stringSize = strlen(line);
            location = strchr(line, '$');
            location += 1;

            /* Input item quantity */
            printf("Please enter quantity: ");
            scanf(" %lf", &item_invent);
            total = atof(location) * item_invent;

            receptFile = fopen(fileName, "a");
            /* Appending 'snprintf' to 'receptFile' */
            if(receptFile == NULL)
            {
                /* File not created hence exit */
                printf("Unable to create file.\n");
                exit(0);
            }

            char buf[1000];
            snprintf(buf, 100, "%0.f x %s Total: $%0.2f\n", item_invent, line, total);

            /* Write data to file */
            fputs(buf, receptFile);
            /* Close file to save file data */
            fclose(receptFile);
        
            printf("\nItem was added to shopping cart\n");
        }
        else if (inventoryFile == NULL)
        {
            printf("Cannot open file \n");
            exit(0);
        }

    }
    if (stock < 1)
        {
            printf("Item out of stock.\n");
        }
      fclose(inventoryFile);
      
}

void repeatMenu()
{
// Reprint menu to screen
    printf("\nHere is our menu:\n\n");
    printf("    D = Display list of merchandise in current inventory\n");
    printf("    P = Purchase an item\n");
    printf("    R = Repeat this menu\n");
    printf("    V = View shopping cart\n");
    printf("    X = Exit, compute amount due, generate receipt.\n");
}

void viewShopcaart()
{   
    FILE *receptFile;
// Open 'receipt' file
    receptFile = fopen(fileName, "r");
    if (receptFile == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }

// Read contents from 'receipt' file
    printf("Your shopping cart is: \n");
    c = fgetc(receptFile);
    printf("\n");
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(receptFile);
    }
    printf("\n");
    fclose(receptFile);

}
