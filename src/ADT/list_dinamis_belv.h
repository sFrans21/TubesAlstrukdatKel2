/* file dynamic_list.h */

#include "boolean.h"
#include "mesinkata.h"
#include "list_linier_belv.h"

#ifndef __DYNAMIC_LIST_H__
#define __DYNAMIC_LIST_H__

#define IdxType int
#define MaxEl 100

typedef struct {
    Word judulPlaylist;
    LinierList judulLagu;
    int countLaguListLinier;
} RincianPlaylist;
typedef struct
{
    RincianPlaylist *IsiPlaylist;
    int Neff;
} DynamicList;


void InsertLastDynamic(DynamicList *list, RincianPlaylist word);

#endif