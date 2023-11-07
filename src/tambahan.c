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