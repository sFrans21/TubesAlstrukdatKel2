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
#include "queue.h"
#include "song.h"
#include "list.h"
#include "ADT/struc.h"






void savefile(char *filename, QueueLagu  *UrutanLagu, ListPlaylist *Playlist, HistoriLagu *RiwayatLagu);

#endif
