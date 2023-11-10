#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tambahan.h"
#include "ADT/mesinkata.h"


boolean isEqual(Word word1, Word word2)
{
    boolean found = false;
    int check = 0;
    if (word1.Length == word2.Length)
    {
        found = true;
        while (check < word1.Length && found)
        {
            if (word1.TabWord[check] != word2.TabWord[check])
            {
                found = false;
            }
            else
            {
                check++;
            }
        }
    }

    return (found);
}

int WordToInt(Word word)
{
    int val = 0;
    int i;
    for (i = 0; i < word.Length; i++)
    {
        val = val * 10 + (int)(word.TabWord[i] % 48);
    }

    return (val);
}

char *WORDTOSTRING(Word kata)
{
    char *akusisiKata = NULL;

    akusisiKata = malloc(kata.Length * sizeof(char));
    int i = 0;
    while (i < kata.Length)
    {
        *(akusisiKata + i) = kata.TabWord[i];
        i++;
    }
    akusisiKata[i] = '\0';
    return akusisiKata;
}

void wordToString(Word currentWord, char *string)
{
    int i = 0;
    while (i < currentWord.Length)
    {
        string[i] = currentWord.TabWord[i];
        i++;
    }
    string[i] = '\0';
}

void stringConcat(char str1[] , char str2[] , char *output)
{
    int i=0,j=0;
    while(str1[i]!='\0'){
        output[i] = str1[i];
        i++;
    }

    while(str2[j]!='\0'){
        output[i]=str2[j];
        j++;
        i++;
    }
    output[i]='\0';
}