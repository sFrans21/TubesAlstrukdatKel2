#ifndef LOAD_H
#define LOAD_H

#include "start.h" // Termasuk file header yang diperlukan
#include ".\ADT\set.h"  // Mungkin memerlukan tipe data seperti Set untuk menyimpan lagu
#include ".\ADT\map.h"   // Memerlukan Map untuk menyimpan album dan lagu
#include ".\ADT\list.h"  // Memerlukan List statis untuk daftar penyanyi

// Deklarasi fungsi untuk membaca save file
int loadSaveFile(const char *filename, Map *penyanyiAlbums, Map *albumLagu, List *penyanyiList);

#endif