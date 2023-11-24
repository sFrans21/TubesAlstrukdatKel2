#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "nyoba.h"

// ========================================================================================= DELAY LOAD ======================================================================================================== //

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

// ========================================================================================= WELCOME pics ======================================================================================================== //

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
// ========================================================================================= START pics ======================================================================================================== //
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
// ========================================================================================= LOAD pics ======================================================================================================== //
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
// ========================================================================================= QUIT pics ======================================================================================================== //
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