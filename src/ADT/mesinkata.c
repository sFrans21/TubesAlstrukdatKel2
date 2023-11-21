#include <stdio.h>

#include "mesinkata.h"

boolean EndWord;
Word currentWord;
Word currentCommand;

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

void StartCommand() {
    START();
    IgnoreNewline();
    if (currentChar == MARK){
        EndWord = true;
    } else {
        EndWord = false;
        CopyCommand();
    }
}

void CopyCommand() {
    ResetCommand(); 
    int i = 0;
    while ((currentChar != BLANK) && (currentChar != MARK) && (currentChar != EOF))
    {
        currentCommand.TabWord[i] = currentChar;
        i+= 1;
        ADV();
    }
    currentCommand.Length = i;
}

void ResetCommand() {
    for (int i = 0; i < sizeof(currentCommand.TabWord); i++) {
        currentCommand.TabWord[i] = '\0';
        currentCommand.Length = 0;
    }
}

void ADVInput(){
    IgnoreBlank();
    if (currentChar == MARK){
        EndWord = true;
    } else {
        EndWord = false;
        CopyCommand();
    }
}

boolean IsCommandEqual(Word Input, char * kata)
{   
    boolean equal = true;
    if (Input.Length == stringLen(kata))
    {
        int i = 0;
        while (i < Input.Length && equal)
        {
            if (Input.TabWord[i] != kata[i])
            {
                equal = false;
            } else {
                i++;
            }
        }
        return equal;
    }
    else
    {
        return false;
    }
}

void copyString(char dest[], const char src[], int max_length) {
    int i = 0;
    while (*src != '\0' && i < max_length - 1) {
        dest[i] = *src;
        i++;
        src++;
    }
    dest[i] = '\0';
}

int stringLen(char *string)
{
    int i = 0;
    int count = 0;
    while (string[i]!='\0') {
        count++;
        i++;
    }
    return count;
}

Word stringToWord(const char str[]) {
    Word word;
    copyString(word.TabWord, str, NMax);
    word.Length = stringLen(str);
    return word;
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