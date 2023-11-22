

typedef struct
{
      Word JudulLagu;
      Word NamaAlbum;
      Word NamaPenyanyi;
      Word NamaPlaylist;
      int status;
      int statusPL;
} CurrentSong;

typedef struct
{
      Word NamaUser;
      int idUser;
      int status;
} CurrentUser;

#ifndef LIST_H
#define LIST_H

#include "../ADT/listStatik.h"
#include "../ADT/map.h"
#include "../ADT/set.h"
#include "../ADT/list_dinamis.h"
// #include "string.h"
#include "../boolean.h"
#include "../tambahan.h"

void PrintPenyanyi(StaticList M);

void PrintAlbum(StaticList N, Map M, Word C);

void PrintLagu(maps M, Word C, int i);

void PrintPlaylist(DynamicList M);

void PutarLagu();

#endif