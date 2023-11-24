#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "nyoba.h"

void clearScreen() 
{
    system("clear || cls");
}

// ========================================================================================= delay ======================================================================================================== //

void delay(int seconds)
{
    int mseconds = 500 * seconds;
    clock_t goal = clock();
 
    while (clock() < goal + mseconds);
}

// ========================================================================================= pics ======================================================================================================== //

void pics(FILE *ASCII)
{
    char readstr[MAX_LEN];
    while(fgets(readstr,sizeof(readstr), ASCII) != NULL)
    printf("%s%s", Yellow, readstr);
    printf("\n");
}

// ========================================================================================= welcome ======================================================================================================== //

void welcome()
{
    char *filename;
    FILE *ASCII;
    system("cls || clear");
    for (int i = 0; i < 4; i++)
    {
        if (i == 0)
        {
            filename = "Tambahan/w/wv1.txt";
        }
        else if (i == 1)
        {
            filename = "Tambahan/w/wv2.txt";
        }
        else
        {
            filename = "Tambahan/w/wv3.txt";
        } 

        ASCII = NULL;
        ASCII = fopen(filename,"r");

        if (ASCII == NULL)
        {
            printf("error opening %s\n",filename);
        }
        else
        {
            system("cls || clear");
            pics(ASCII);
            fclose(ASCII);
        }
        delay(1);
    }
}
// ========================================================================================= starting ======================================================================================================== //
void starting()
{
    char *filename;
    FILE *ASCII;
    system("cls || clear");
    for (int i = 0; i < 4; i++)
    {
        if (i == 0)
        {
            filename = "Tambahan/s/s1.txt";
        }
        else if (i == 1)
        {
            filename = "Tambahan/s/s2.txt";
        }
        else 
        {
            filename = "Tambahan/s/s3.txt";
        }

        ASCII = NULL;
        ASCII = fopen(filename,"r");

        if (ASCII == NULL)
        {
            printf("error opening %s\n",filename);
        }
        else
        {
            system("cls || clear");
            pics(ASCII);
            fclose(ASCII);
        }
        delay(1);
    }
}
// ========================================================================================= loading ======================================================================================================== //
void loading()
{
    char *filename;
    FILE *ASCII;
    system("cls || clear");
    for (int i = 0; i < 4; i++)
    {
        if (i == 0)
        {
            filename = "Tambahan/ld/ld1.txt";
        }
        else if (i == 1)
        {
            filename = "Tambahan/ld/ld2.txt";
        }
        else 
        {
            filename = "Tambahan/ld/ld3.txt";

        }
        ASCII = NULL;
        ASCII = fopen(filename,"r");

        if (ASCII == NULL)
        {
            printf("error opening %s\n",filename);
        }
        else
        {
            system("cls || clear");
            pics(ASCII);
            fclose(ASCII);
        }
        delay(1);
    }
}
// ========================================================================================= quitting ======================================================================================================== //
void quitting()
{
    char *filename;
    FILE *ASCII;
    system("cls || clear");
    for (int i = 0; i < 4; i++)
    {
        if (i == 0)
        {
            filename = "Tambahan/quit/quit_1.txt";
        }
        else if (i == 1)
        {
            filename = "Tambahan/quit/quit_2.txt";
        }
        else if (i == 2)
        {
            filename = "Tambahan/quit/quit_3.txt";
        } 
        else
        {
            filename = "Tambahan/quit/quit_4.txt";
        }

        ASCII = NULL;
        ASCII = fopen(filename,"r");

        if (ASCII == NULL)
        {
            printf("error opening %s\n",filename);
        }
        else
        {
            system("cls || clear");
            pics(ASCII);
            fclose(ASCII);
        }
        delay(1);
    }
}

void displayLoadingBar(int progress) {
    printf("\033[1;33m"); // Set text color to yellow
    printf("Loading: [");
    for (int i = 0; i < 20; ++i) {
        if (i < progress / 5) {
            printf("=");
        } else {
            printf(" ");
        }
    }
    printf("] %d%%\n", progress);
    printf("\n\033[0m\n"); // Reset text color
}

void animateSpinner(int duration) {
    const char spinner[] = { '|', '/', '-', '\\' };
    int i = 0;
    time_t start_time = time(NULL);
    int progress = 0;

    // displayHeader();

    while ((time(NULL) - start_time) < duration) {
        clearScreen();
        // displayHeader();
        displayLoadingBar(progress);
        printf("\033[1;33m"); // Set text color to yellow
        printf("Loading... %c\n", spinner[i]);
        printf("\033[0m\n"); // Reset text color

        // Update loading progress
        progress = (int)(((time(NULL) - start_time) / (double)duration) * 125);

        // Delay for animation effect
        for (int j = 0; j < 70000000; j++) {
            // Intentional delay to simulate animation
        }

        i = (i + 1) % 4; // Cycle through spinner characters
    }
    {
        clearScreen();
    }
}