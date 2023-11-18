#include <stdio.h>

#include "mesinkarakter.h"

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void START()
{
    pita = stdin;
    ADV();
}

void StartFile(char *filename)
{
    if (filename == NULL){
        pita = stdin;
    } else {
        pita = fopen(filename, "r");
    }
    ADV();
}
 
void ADV()
{
    if (pita == NULL)
    {
        EOP = true;
    }
    else
    {
        retval = fscanf(pita, "%c", &currentChar);
        EOP = feof(pita);

        if (EOP)
        {
            fclose(pita);
        }
    }
}

void AdvFile()
{
    if (pita == NULL)
    {
        EOP = true;
    }
    else
    {
        retval = fscanf(pita, "%c", &currentChar);
        EOP = feof(pita);

        if (EOP)
        {
            fclose(pita);
        }
    }
}

char GetCC()
{
    return (currentChar);
}

boolean IsEOP()
{
    return (currentChar == MARK);
}