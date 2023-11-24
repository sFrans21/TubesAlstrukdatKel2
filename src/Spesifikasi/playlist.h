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
#include "../tambahan.h"


void CreatePlaylist ();

void PlaylistAddSong(StaticList penyanyi, Map penyanyiAlbums, maps albumsong);

void PlaylistAddAlbum(StaticList penyanyi, Map penyanyiAlbums, maps albumsong);

void PlaylistSwap(Word Word);

void PlaylistRemove(Word Word);

void PlaylistDelete();

#endif

