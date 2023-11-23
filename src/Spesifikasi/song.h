
#ifndef __SONG_H_
#define __SONG_H_

#include "ADT/queue_belv.h"  
#include "ADT/stack_belv.h"
#include "ADT/mesinkata.h"


void SongNext(SQueue * q, RiwayatLagu * RL, CurrentSong* CS);

void SongPrev(SQueue * q, RiwayatLagu * RL, CurrentSong* CS);

#endif