#ifndef _PLAY_H
#define _PLAY_H

#include "../ADT/listStatik.h"
#include "../ADT/map.h"
#include "../ADT/set.h"
#include "../ADT/list_dinamis.h"
// #include "string.h"
#include "../boolean.h"
#include "../tambahan.h"
#include "../ADT/mesinkata.h"
// typedef struct
// {
//       Word JudulLagu;
//       Word NamaAlbum;
//       Word NamaPenyanyi;
//       Word NamaPlaylist;
//       int status;
//       int statusPL;
// } CurrentSong;

typedef struct
{
      Word NamaUser;
      int idUser;
      int status;
} CurrentUser;

void PrintPenyanyii(StaticList M);

void PrintAlbumm(StaticList N, Map M, Word C);

void PrintLaguu(maps M, Word C, int i);

void PrintPlaylistt(DynamicList M);

int IdxKetemuPenyanyi(StaticList M, Word C);

// void PutarLagu();

#endif