#include<stdio.h>
#include<stdlib.h>
#include "list_dinamis_belv.h"
#include <stdbool.h>

void InsertLastDynamic(DynamicList *list, RincianPlaylist word)
{
    list->IsiPlaylist[list->Neff] = word;
    list->Neff++;
}