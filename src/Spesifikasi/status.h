#ifndef STATUS_H
#define STATUS_H
#include "start.h" // Termasuk file header yang diperlukan
#include "../ADT/stack.h"  // Mungkin memerlukan tipe data seperti Set untuk menyimpan lagu
#include "../ADT/arrayDin.h"
// #include "../ADT/Queue.h"  // Memerlukan List statis untuk daftar penyanyi

#include "save.h"
#include "../tambahan.h"
#include "queue.h"
#include "song.h"
#include "list.h"
#include "../ADT/list_linier.h"
#include "../ADT/Queue.h"



void displayStatus(StaticList *penyanyi, Map *penyanyiAlbums, maps *albumsong , Queue *UrutanLagu, ArrayDin *Playlist);

#endif
