#ifndef __QUEUE_H_
#define __QUEUE_H_

#include "ADT/mesinkata.h"
#include "ADT/listStatik.h"
#include "ADT/map.h"
#include "ADT/set.h"
#include "ADT/Queue.h"

void queuesong(StaticList penyanyi, Map singeralbum, maps albumsong, Queue *kiw);

void queueswap(Queue *kiw, int idx1, int idx2);

void queueremove(Queue *kiw, int i);

void  queueclear(Queue *kiw);

#endif