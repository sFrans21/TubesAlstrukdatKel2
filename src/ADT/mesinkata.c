#include <stdio.h>

#include "mesinkata.h"

boolean EndWord;
Word currentWord;
Word currentCommand;
Word hasil;

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

void StartWordMark()
{
    StartMark();
    IgnoreBlanks();
    IgnoreNewlines();
    if (IsEOPMark())
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWordMark();
    }
}

void StartWordBlank()
{
    StartBlank();
    IgnoreMarks();
    IgnoreBlanks();
    IgnoreNewlines();
    if (IsEOPBlank())
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWordNewline();
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

void DisplayWord(Word word)
{
    for (int i = 0; i < word.Length; i++)
    {
        printf("%c", word.TabWord[i]);
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

Word stringToWord(char* str) {
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

void ADVSemicolon(){
    hasil.Length = 0;
    while((currentChar != MARK) && (currentChar != NEWLINE) && (currentChar != STRIP) && (currentChar != STOP)){
        hasil.TabWord[hasil.Length] = currentChar;
        hasil.Length++;
        ADV();
    }
    if(currentChar == MARK){ 
        ADV();
    }
}

boolean CekWord(Word hasil){
    boolean ada = false;
    if(hasil.Length != 0){
        ada = true;
    }
    return ada;
}

Word SplitWordBlank(Word word)
{
    Word temp;
    int sum = 0, idx;
    for (int i = 0; i < word.Length; i++)
    {
        if (word.TabWord[i] == BLANK)
        {
            idx = i;
            break;
        }
    }

    for (int i = (idx + 1); i < word.Length; i++)
    {
        temp.TabWord[sum] = word.TabWord[i];
        sum++;
    }
    temp.Length = sum;

    return (temp);
}

Word SplitWordMark(Word word)
{
    Word temp;
    int sum = 0, idx;
    for (int i = 0; i < word.Length; i++)
    {
        if (word.TabWord[i] == MARK)
        {
            idx = i;
            break;
        }
    }

    for (int i = (idx + 1); i < word.Length; i++)
    {
        temp.TabWord[sum] = word.TabWord[i];
        sum++;
    }
    temp.Length = sum;

    return (temp);
}

Word SplitWordLeftBlank(Word word)
{
    Word temp;
    int sum = 0, idx;
    for (int i = 0; i < word.Length; i++)
    {
        if (word.TabWord[i] == BLANK)
        {
            idx = i;
            break;
        }
    }

    for (int i = 0; i < idx; i++)
    {
        temp.TabWord[sum] = word.TabWord[i];
        sum++;
    }
    temp.Length = sum;

    return (temp);
}

Word SplitWordLeftMark(Word word)
{
    Word temp;
    int sum = 0, idx;
    for (int i = 0; i < word.Length; i++)
    {
        if (word.TabWord[i] == MARK)
        {
            idx = i;
            break;
        }
    }

    for (int i = 0; i < idx; i++)
    {
        temp.TabWord[sum] = word.TabWord[i];
        sum++;
    }
    temp.Length = sum;

    return (temp);
}