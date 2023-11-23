#ifndef SAVE_H
#define SAVE_H

#include "start.h" // Termasuk file header yang diperlukan  // Mungkin memerlukan tipe data seperti Set untuk menyimpan lagu
// #include "../ADT/arrayDin.h"   // Memerlukan Map untuk menyimpan album dan lagu
//#include "../ADT/Queue.h"  // Memerlukan List statis untuk daftar penyanyi
#include "../tambahan.h"
#include "queue.h"
#include "../ADT/Queue.h"
#include "../ADT/list_dinamis.h"
#include "../ADT/list_linier.h"
#include "../ADT/stack.h"



void save(char *inputfile, StaticList *penyanyi, Map *penyanyiAlbums, maps *albumsong, Queue *UrutanLagu, DynamicList *Playlist, Stack *History, LinierList *LaguPlaylist, CurrentSong *CS);

#endif

