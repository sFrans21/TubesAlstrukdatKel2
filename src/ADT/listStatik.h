#ifndef STATICLIST_H
#define STATICLIST_H

#include "mesinkata.h"
#define Nil 0
#define MaxElMap 50
#define Undefined NULL
#define MAX_ITEMS 100
#define MaxElSet 100
#define MAX_ITEMS 100

typedef struct
{
    Word items[MAX_ITEMS];
    int itemCount;
} StaticList;

void initializeList(StaticList *list);
void setItem(StaticList *list, int index, Word *item); // Menambahkan fungsi setItem
void displayList(const StaticList *list);

#endif