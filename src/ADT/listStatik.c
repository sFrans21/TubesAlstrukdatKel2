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
void displayList(const StaticList *list)
{
    for (int i = 0; i < list->itemCount; i++)
    {
        printf("%s\n", list->items[i].TabWord);
    }
}


Word GetStatic(StaticList list, IdxType i){
    return (list.items[i]);
}

void InsertLastStatic(StaticList *list, Word word){
    int count = 0;

    while (!IsCommandEqual(list->items[count], MarkStatic))
    {
        count++;
    }
    list->items[count] = word;
}
