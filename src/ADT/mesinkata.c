#include <stdio.h>

#include "mesinkata.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks()
{
    while (currentChar == BLANK)
    {
        ADV();
    }
}

void IgnoreNewlines()
{
    while (currentChar == NEWLINE)
    {
        AdvFile();
    }
}

void StartWordInput()
{
    START();
    IgnoreBlanks();
    if (IsEOP())
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
    }
}

void StartWordFile(char *filename)
{
    StartFile(filename);
    if (currentChar == NEWLINE)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        AdvWordFile();
    }
}

void AdvWord()
{
    IgnoreBlanks();
    if (currentChar == BLANK)
    {
        EndWord = true;
    }
    else
    {
        CopyWord();
        IgnoreBlanks();
    }
}

void AdvWordFile()
{
    if (currentChar == NEWLINE)
    {
        EndWord = true;
    }
    else
    {
        CopyWordFile();
        IgnoreNewlines();
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