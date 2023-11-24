#ifndef __QUEUE_H_
#define __QUEUE_H_


#include "../ADT/mesinkarakter.h"
#include "../ADT/mesinkata.h"
#include "../ADT/listStatik.h"
#include "../ADT/map.h"
#include "../ADT/set.h"
#include "../ADT/Queue.h"
#include "../ADT/list_linier.h"

void queuesong(StaticList penyanyi, Map singeralbum, maps albumsong, Queue *queue);

void queueswap(Queue *queue, int idx1, int idx2);

void queueremove(Queue *queue, int i);

void queueclear(Queue *queue);

void queueplaylist(MapPlaylist PL, Queue *queue);

#endif
