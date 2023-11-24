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
#include "play.h"

void CreatePlaylist (DynamicList playlist);

<<<<<<< HEAD
void PlaylistAddSong(StaticList penyanyi, Map penyanyiAlbums, maps albumsong, DynamicList Playlist);
=======
void CreatePlaylist ();

void CreatePlaylist (Word CPlaylist);
>>>>>>> bc402a5970eafe537b13c83e98831b5f73ffdf59

void PlaylistAddSong(StaticList *penyanyi, Map *penyanyiAlbums, maps *albumsong ,DynamicList *DaftarPlaylist);

void PlaylistSwap(Word Word);

void PlaylistRemove(Word Word);

void PlaylistDelete();

#endif

