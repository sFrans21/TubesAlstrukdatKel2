#include <stdio.h>
#include "list.h"

void list()
{
    /*List Default*/
    char n[50];
    scanf("%s", n);

    if (compareStrings(n, "LIST DEFAULT") == 0)
    {
        char penyanyi[4][150] = {"Blackpink", "kanye", "yb", "travis"};
        printf("Daftar Penyanyi : \n");
        for (int i = 0; i <= 4; i++)
        {
            printf("%s\n", penyanyi[i]);
        }
    }

    // else if  (n == "LIST PLAYLIST")
    // {

    // }
}

// kita nyimpen penyanyi, album, sama lagunya di array

int compareStrings(const char *str1, const char *str2)
{
    while (*str1 && *str2 && *str1 == *str2)
    {
        str1++;
        str2++;
    }

    if (*str1 == *str2)
    {
        return 0; // Kedua string identik
    }
    else if (*str1 < *str2)
    {
        return -1; // str1 kurang dari str2
    }
    else
    {
        return 1; // str1 lebih besar dari str2
    }
}

int main()
{
    /*List Default*/
    char n[50];
    scanf("%s", n);

    if (compareStrings(n, "LIST DEFAULT") == 0)
    {
        char penyanyi[4][150] = {"Blackpink", "kanye", "yb", "travis"};
        printf("Daftar Penyanyi : \n");
        for (int i = 0; i <= 4; i++)
        {
            printf("%s\n", penyanyi[i]);
        }
    }

    // else if  (n == "LIST PLAYLIST")
    // {

    // }
}