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



void CreatePlaylist (Word CPlaylist);

void PlaylistAddSong(StaticList *penyanyi, Map *penyanyiAlbums, maps *albumsong ,DynamicList *DaftarPlaylist);

void PlaylistAddAlbum(StaticList penyanyi, Map singeralbum, maps albumsong ,DynamicList *DaftarPlaylist);

void PlaylistSwap(DynamicList DaftarPlaylist, int idx1, int idx2);

void PlaylistRemove(DynamicList DaftarPlaylist);

void PlaylistDelete(DynamicList DaftarPlaylist);
#endif

