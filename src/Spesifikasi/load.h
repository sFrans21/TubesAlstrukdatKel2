#ifndef LOAD_H
#define LOAD_H

#include "start.h" // Termasuk file header yang diperlukan
#include "../ADT/stack.h"  // Mungkin memerlukan tipe data seperti Set untuk menyimpan lagu
#include "../ADT/list_dinamis.h"   // Memerlukan Map untuk menyimpan album dan lagu
#include "../ADT/Queue.h"  // Memerlukan List statis untuk daftar penyanyi
#include "../ADT/list_linier.h"
#include "../Tambahan/color.h"

// Deklarasi fungsi untuk membaca save file
void load(char *inputfile, StaticList *penyanyi, Map *penyanyiAlbums, maps *albumsong, Queue *UrutanLagu, DynamicList *Playlist, Stack *RiwayatLagu, LinierList *LaguPlaylist, Word *currentSong);

#endif