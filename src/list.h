#ifndef LIST_H
#define LIST_H

#include "ADT/listStatik.h"
#include "ADT/map.h"
#include "ADT/set.h"
#include "ADT/list_dinamis.h"
#include "string.h"
#include "boolean.h"
#include "tambahan.h"

// #define Nil 0
// #define MaxElMap 50
// #define Undefined NULL
// #define MAX_ITEMS 100
// #define MaxElSet 100

// typedef struct
// {
//       char TabWord[50];
//       int Length;
// } Word;

// typedef Word infotypeSet;
// typedef int addrSer;

// typedef struct
// {
//       infotypeSet Elements[MaxElSet];
//       addrSer Count;
// } Set;

// typedef struct
// {
//       Word items[MAX_ITEMS];
//       int itemCount;
// } StaticList;

// typedef struct
// {
//       Word Key;
//       Set Value;
// } infotype2;

// typedef struct
// {
//       infotype2 Elements[MaxElMap];
//       int Count;
// } Map;

void PrintPenyanyi(StaticList M);

void PrintAlbum(Map M, Word C);

void PrintLagu(Map M, Word C);

void PrintPlaylist(DynamicList M);

#endif