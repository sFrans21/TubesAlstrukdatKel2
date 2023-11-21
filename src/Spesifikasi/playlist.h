/* File : playlist.h */
/* ADT berisikan fungsi playlist dengan memanfaatkan Dynamic List dan List Linier */

#ifndef __PLAYLIST_H__
#define __PLAYLIST_H__

#include "../ADT/list_dinamis.h"
#include "../ADT/list_linier.h"
#include "../ADT/mesinkata.h"
#include "../ADT/listStatik.h"
#include "../ADT/map.h"

void CreatePlaylist (DynamicList *playlist);

void CreatePlaylist (DynamicList *playlist);

void AddSongPlaylist (StaticList *artist, Map *album_artist, Map *song_album, DynamicList *playlist, LinierList *playlist_song);

void AddAlbumPlaylist (StaticList *artist, Map *album_artist, DynamicList *playlist);

#endif

