/* File : playlist.h */
/* ADT berisikan fungsi playlist dengan memanfaatkan Dynamic List dan List Linier */

#ifndef __PLAYLIST_H__
#define __PLAYLIST_H__

#include "ADT/list_dinamis.h"
#include "ADT/list_linier.h"
#include "ADT/mesinkata.h"
#include "ADT/listStatik.h"
#include "ADT/map.h"
#include "ADT/stack.h"
#include "list.h"
#include "tambahan.h"


void CreatePlaylist (DynamicList *playlist);

void PlaylistAddSong(StaticList lp, Map m2,Set S ,DynamicList *daftarplaylist);

void PlaylistAddAlbum(StaticList lp, Map m2,Set S ,DynamicList *daftarplaylist);

void PlaylistSwap(DynamicList ListDin, int idx1, int idx2);
#endif

