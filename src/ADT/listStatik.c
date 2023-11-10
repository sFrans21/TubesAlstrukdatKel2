#include "listStatik.h"
#include <stdio.h>

void initializeList(StaticList *list) {
    list->itemCount = 0;
}

void setItem(StaticList *list, int index, Word *item) {
    if (index >= 0 && index < list->itemCount) {
        list->items[index] = *item;  // Menyalin Word ke dalam list
    }
}

void displayList(const StaticList *list) {
    for (int i = 0; i < list->itemCount; i++) {
        printf("%s\n", list->items[i].TabWord);
    }
}