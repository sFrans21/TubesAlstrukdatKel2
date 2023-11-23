#ifndef STATUS_H
#define STATUS_H
#include "start.h"
#include "../tambahan.h"
#include "queue.h"
#include "../ADT/Queue.h"
#include "../ADT/list_dinamis.h"
#include "../ADT/list_linier.h"
#include "../ADT/stack.h"


void carialbumpenyanyi(Map singeralbum, maps albumsong, char *songname, char *curP, char *curA);
char* checkQueueInPlaylist(Queue *UrutanLagu, DynamicList *Playlist, maps *albumsong, Map *penyanyiAlbums);
void displayStatus(StaticList *penyanyi, Map *penyanyiAlbums, maps *albumsong, Queue *UrutanLagu, DynamicList *Playlist,  LinierList *LaguPlaylist);

#endif
