#include "listStatik.h"
#include <stdio.h>

void initializeList(StaticList *list)
{
    list->itemCount = 0;
}

void setItem(StaticList *list, int index, Word *item)
{
    if (index >= 0 && index < MAX_ITEMS)
    {
        list->items[index] = *item; // Menyalin Word ke dalam list
        list->itemCount++;
    }
}

void CreateEmptyStatic(StaticList *list)
{
    int i;

    for (i = 0; i < MAX_ITEMS; i++)
    {
        (*list).items[i] = stringToWord(MarkStatic);
    }
}

void displayList(const StaticList *list)
{
    for (int i = 0; i < list->itemCount; i++)
    {
        printf("%s\n", list->items[i].TabWord);
    }
}

void InsertLastStatic(StaticList *list, Word word)
{
    int count = 0;

    while (!CompareStringWord(list->items[count], MarkStatic))
    {
        count++;
    }
    list->items[count] = word;
}

Word GetList(StaticList list, IdxType i)
{
    return  (list.items[i]);
}

int LengthList(StaticList list)
{
    int count = 0;
    while ((!CompareWord(list.items[count], StringToWord(MarkStatic))) && (count <= MAX_ITEMS))
    {
        count++;
    }
    return count;
}

boolean IsListEmpty(StaticList list)
{
    return (LengthList(list) == 0);
}
