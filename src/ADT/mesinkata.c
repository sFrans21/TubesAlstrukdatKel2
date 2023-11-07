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

void AdvWordFile()
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