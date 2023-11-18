#ifndef QUIT_H
#define QUIT_H

#include "ADT/stack.h"  // Mungkin memerlukan tipe data seperti Set untuk menyimpan lagu
#include "ADT/arrayDin.h"   // Memerlukan Map untuk menyimpan album dan lagu
#include "ADT/queue.h"  // Memerlukan List statis untuk daftar penyanyi
#include "load.h"

// Deklarasi fungsi untuk membaca save file
void quit(StaticList *penyanyi, Map *penyanyiAlbums, maps *albumsong, Queue *UrutanLagu, ArrayDin *Playlist, Stack *RiwayatLagu, boolean saved);

#endif