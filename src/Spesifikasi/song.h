
#ifndef __SONG_H_
#define __SONG_H_

#include "queue.h"  
#include "ADT/stack.h"
#include "ADT/mesinkata.h"


void SongNext(Queue * queue, Stack * RiwayatLagu, CurrentSong * currentS);

void SongPrev(Queue * queue, Stack * RiwayatLagu, CurrentSong * currentS);

#endif