#ifndef SAVE_H
#define SAVE_H

#include "start.h" // Termasuk file header yang diperlukan
#include "../ADT/stack.h"  // Mungkin memerlukan tipe data seperti Set untuk menyimpan lagu
// #include "../ADT/arrayDin.h"   // Memerlukan Map untuk menyimpan album dan lagu
//#include "../ADT/Queue.h"  // Memerlukan List statis untuk daftar penyanyi
#include "../tambahan.h"
#include "queue.h"
#include "../ADT/list_linier.h"
#include "../ADT/Queue.h"
#include "../ADT/queue_belv.h"
#include "../ADT/list_dinamis_belv.h"
#include "../ADT/list_linier_belv.h"
#include "../ADT/stack_belv.h"

void save(char *inputfile, StaticList *penyanyi, Map *penyanyiAlbums, maps *albumsong, SQueue *UrutanLagu, DynamicList *Playlist, , LinierList *LaguPlaylist, CurrentSong *CS);

#endif

