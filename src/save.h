#ifndef SAVE_H
#define SAVE_H

#include "start.h" // Termasuk file header yang diperlukan
#include "ADT/stack.h"  // Mungkin memerlukan tipe data seperti Set untuk menyimpan lagu
#include "ADT/arrayDin.h"   // Memerlukan Map untuk menyimpan album dan lagu
#include "ADT/queue.h"  // Memerlukan List statis untuk daftar penyanyi
#include <stdio.h>
#include <stdlib.h>
#include "save.h"
#include "tambahan.h"
#include "ADT/mesinkata.h"
#include "queue.h"
#include "song.h"
#include "list.h"
#include "list_dinamis.h"





// Deklarasi fungsi untuk membaca save file
void savefile(char *filename,  Queue *UrutanLagu, ArrayDin *Playlist, Stack *RiwayatLagu);

#endif
