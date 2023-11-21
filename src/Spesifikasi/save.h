#ifndef SAVE_H
#define SAVE_H

#include "start.h" // Termasuk file header yang diperlukan
#include "../ADT/stack.h"  // Mungkin memerlukan tipe data seperti Set untuk menyimpan lagu
// #include "../ADT/arrayDin.h"   // Memerlukan Map untuk menyimpan album dan lagu
#include "../ADT/Queue.h"  // Memerlukan List statis untuk daftar penyanyi

#include "save.h"
#include "../tambahan.h"
#include "queue.h"
#include "song.h"
#include "list.h"
#include "../ADT/list_linier.h"
#include "../ADT/Queue.h"


void save(char *filename, StaticList *penyanyi, Map *penyanyiAlbums, maps *albumsong, Queue *UrutanLagu, DynamicList *Playlist, Stack *RiwayatLagu, LinierList *LaguPlaylist);

#endif

