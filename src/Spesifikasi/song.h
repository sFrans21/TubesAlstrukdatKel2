
#ifndef __SONG_H_
#define __SONG_H_

#include "ADT/queue.h"  
#include "ADT/stack.h"
#include "ADT/mesinkata.h"
#include "ADT/list_dinamis.h"
#include "load.h"




void SongNext(Queue * q, Stack * RL, currentSong * CS);

void SongPrev(Queue * q, Stack * RL, currentSong * CS);

#endif