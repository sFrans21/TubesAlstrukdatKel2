// void list();

#include <stdio.h>
#include <string.h>

#define MAX_ALBUMS 50
#define MAX_SONGS_PER_ALBUM 20

// Struktur untuk lagu
struct Song
{
      char title[100];
};

// Struktur untuk album
struct Album
{
      char name[100];
      struct Song songs[MAX_SONGS_PER_ALBUM];
      int numSongs;
};


