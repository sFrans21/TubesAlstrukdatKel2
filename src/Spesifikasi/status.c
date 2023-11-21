#include <stdio.h>
#include "../tambahan.h"
#include "status.h"



void carialbumpenyanyi(Map singeralbum, maps albumsong, char *songname, char *curP, char *curA) {
    // Pencarian lagu dalam struktur data albumsong
    int found = 0;  // Flag untuk menandakan apakah lagu ditemukan
    int idxp, idxa, idxl;

    for (idxp = 0; idxp < singeralbum.Count; idxp++) {
        for (idxa = 0; idxa < singeralbum.Elements[idxp].Value.Count; idxa++) {
            for (idxl = 0; idxl < albumsong.Elements[idxp].Elements[idxa].Value.Count; idxl++) {
                // Menggunakan strcmp untuk membandingkan string
                if (strcmp(songname, albumsong.Elements[idxp].Elements[idxa].Value.Elements[idxl].TabWord) == 0) {
                    found = 1;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        if (found) {
            break;
        }
    }
}

char* checkQueueInPlaylist(Queue *UrutanLagu, DynamicList *Playlist, maps *albumsong, Map *penyanyiAlbums) {
    // Cek apakah semua lagu dalam queue berada dalam suatu playlist
    for (int i = UrutanLagu->idxHead; i < UrutanLagu->idxTail; i++) {
        char currsong[50];
        char currPen[50];
        char currAlb[50];

        strcpy(currsong, UrutanLagu->buffer[i].TabWord);
        carialbumpenyanyi(*penyanyiAlbums, *albumsong, currsong, currPen, currAlb);

        boolean foundInPlaylist = false;

        // Iterasi melalui playlist untuk mencari lagu
        for (int j = 1; j <= LengthListDynamic(Playlist[0]); j++) {
            if (strcmp(currsong, Playlist[0].A[j].TabWord) == 0) {
                foundInPlaylist = true;
                break;
            }
        }

        // Jika lagu tidak ditemukan dalam playlist, maka tidak semua lagu berada dalam playlist
        if (!foundInPlaylist) {
            return NULL;
        }
    }

    // Jika semua lagu ditemukan dalam playlist, kembalikan nama playlist
    return Playlist[0].A[0].TabWord;
}
void displayStatus(StaticList *penyanyi, Map *penyanyiAlbums, maps *albumsong , Queue *UrutanLagu, DynamicList *Playlist)
{
    printf(">> STATUS;\n");

    // Cek apakah ada lagu yang sedang diputar
    if (isQueueEmpty(*UrutanLagu))
    {
        printf("Now Playing : \n No songs have been played yet. Please search for a song to begin playback.\n");
        printf("\nQueue:\n");
        printf("Your queue is empty.\n");
    }
    else {
        printf("// Ada lagu yang sedang diputar\n");
            char currsong[50];
            char currPen[50];
            char currAlb[50];

            strcpy(currsong, HEAD(*UrutanLagu).TabWord);
            carialbumpenyanyi(*penyanyiAlbums, *albumsong, currsong, currPen, currAlb);
            printf("Now Playing:\n");
            printf("%s - %s - %s\n", HEAD(*UrutanLagu).TabWord, currAlb, currPen);


        if (lengthQueue(*UrutanLagu) == 1)
        {
            printf("\nQueue:\n");
            printf("Your queue is empty.\n");
        }
        else{
            int a = 1;
            for (int i = UrutanLagu->idxHead ; i < UrutanLagu->idxTail;i++){
            char currsong[50]; 
            char currPen[50];
            char currAlb[50];

            strcpy(currsong, UrutanLagu->buffer[i].TabWord);
            carialbumpenyanyi(*penyanyiAlbums, *albumsong, currsong, currPen, currAlb);
            printf("\nQueue:\n");
            printf("%d. %s - %s - %s\n", a, HEAD(*UrutanLagu).TabWord, currAlb, currPen);
            a++;
            }
        }
    }
     char* playlistName = checkQueueInPlaylist(UrutanLagu, Playlist, albumsong, penyanyiAlbums);

    // Jika playlistName bukan NULL, maka tampilkan nama playlist
    if (playlistName != NULL) {
        printf("\nCurrent Playlist: %s\n", playlistName);
    }
}
