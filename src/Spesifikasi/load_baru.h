#ifndef LOAD_H
#define LOAD_H

#include "start.h" // Termasuk file header yang diperlukan
#include "../ADT/stack_belv.h"  // Mungkin memerlukan tipe data seperti Set untuk menyimpan lagu
#include "../ADT/list_dinamis_belv.h"   // Memerlukan Map untuk menyimpan album dan lagu
#include "../ADT/queue_belv.h"  // Memerlukan List statis untuk daftar penyanyi
#include "../ADT/list_linier_belv.h"

// Deklarasi fungsi untuk membaca save file
void load(char *inputfile, StaticList *penyanyi, Map *penyanyiAlbums, maps *albumsong, Queue *UrutanLagu, DynamicList *Playlist, Stack *RiwayatLagu, LinierList *LaguPlaylist);

#endif