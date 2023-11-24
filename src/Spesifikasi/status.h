#ifndef STATUS_H
#define STATUS_H
#include "start.h"
#include "../tambahan.h"
#include "queue.h"
#include "../ADT/map.h"
#include "save.h"

void carialbumpenyanyi(Map singeralbum, maps albumsong, char *songname, char *curP, char *curA);
char* checkQueueInPlaylist(Queue *UrutanLagu, MapPlaylist *Playlist, maps *albumsong, Map *penyanyiAlbums);
void displayStatus(StaticList *penyanyi, Map *penyanyiAlbums, maps *albumsong , Queue *UrutanLagu, MapPlaylist *Playlist, Word *currentSong);

#endif
