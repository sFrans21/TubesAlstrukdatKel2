#ifndef LOAD_H
#define LOAD_H

#include "start.h" // Termasuk file header yang diperlukan
#include "ADT/stack.h"  // Mungkin memerlukan tipe data seperti Set untuk menyimpan lagu
#include "ADT/arrayDin.h"   // Memerlukan Map untuk menyimpan album dan lagu
#include "ADT/queue.h"  // Memerlukan List statis untuk daftar penyanyi
#include "ADT/list_linier.h"

// Deklarasi fungsi untuk membaca save file
void load(char *inputfile, StaticList *penyanyi, Map *penyanyiAlbums, maps *albumsong, Queue *UrutanLagu, ArrayDin *Playlist, Stack *RiwayatLagu, LinierList *LaguPlaylist);

#endif