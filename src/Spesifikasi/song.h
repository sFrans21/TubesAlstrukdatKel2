
#ifndef __SONG_H_
#define __SONG_H_

#include "ADT/Queue.h"  
#include "ADT/stack.h"
#include "ADT/mesinkata.h"
#include "ADT/list_dinamis.h"
#include "load.h"


void SongNext(StaticList *penyanyi, Map *penyanyiAlbums, maps *albumsong ,Stack *RiwayatLagu, Queue *UrutanLagu,  Word *currentSong);


void SongPrev(StaticList *penyanyi, Map *penyanyiAlbums, maps *albumsong ,Stack *RiwayatLagu, Queue *UrutanLagu,  Word *currentSong);


#endif