#ifndef STATUS_H
#define STATUS_H
#include "start.h" // Termasuk file header yang diperlukan
#include "../ADT/stack.h"  // Mungkin memerlukan tipe data seperti Set untuk menyimpan lagu
#include "../ADT/list_dinamis.h"  // Memerlukan Map untuk menyimpan album dan lagu  // Memerlukan List statis untuk daftar penyanyi

#include "../tambahan.h"
#include "queue.h"
#include "list.h"
#include "../ADT/list_linier.h"
#include "../ADT/Queue.h"
#include "../ADT/map.h"
#include "../ADT/queue_belv.h"

void carialbumpenyanyi(Map singeralbum, maps albumsong, char *songname, char *curP, char *curA);
char* checkQueueInPlaylist(Queue *UrutanLagu, DynamicList *Playlist, maps *albumsong, Map *penyanyiAlbums);
void displayStatus(StaticList *penyanyi, Map *penyanyiAlbums, maps *albumsong , Queue *UrutanLagu, DynamicList *Playlist);

#endif
