#include <stdio.h>

#include "mesinkata.h"

boolean EndWord;
Word currentWord;

void IgnoreBlank()
{
    while (currentChar == BLANK)
    {
        ADV();
    }
}

void IgnoreNewline()
{
    while (currentChar == NEWLINE)
    {
        AdvFile();
    }
}

void StartWordInput()
{
    START();
    IgnoreBlank();
    IgnoreNewline();
    if (IsEOP())
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWordinput();
    }
}

void StartWordFile(char *filename, int type)
{
    if (type == 0)
    {
        StartFile(filename);
        IgnoreBlank();
        if (currentChar == '\n')
        {
            EndWord = true;
        }
        else
        {
            EndWord = false;
            CopyWord(type);
        }
    }
    else
    {
        StartFile(filename);
        if (currentChar == NEWLINE)
        {
            EndWord = true;
        }
        else
        {
            EndWord = false;
            ADVLine();
        }
    }
}

void ADVWord()
{
    IgnoreBlank();
    if (currentChar == BLANK)
    {
        EndWord = true;
    }
    else
    {
        CopyWord();
        IgnoreBlank();
    }
}

void ADVLine()
{
    if (currentChar == NEWLINE)
    {
        EndWord = true;
    }
    else
    {
        CopyWordFile();
        IgnoreNewline();
    }
}

void CopyWord()
{
    int i = 0;

    while ((!IsEOP()) && (currentChar != BLANK))
    {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    currentWord.Length = i;
}

Word CopyWordFile()
{
    int i = 0;

    while ((!EOP) && currentChar != NEWLINE)
    {
        currentWord.TabWord[i] = currentChar;
        AdvFile();
        i++;
    }
    currentWord.Length = i;
}

void CopyWordinput(){
    int i = 0;
    while ((!IsEOP()))
    {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    } 
    currentWord.Length = i;
}