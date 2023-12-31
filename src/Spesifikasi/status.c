#include <stdio.h>
#include "../tambahan.h"
#include "status.h"
#include <stdlib.h>

void carialbumpenyanyi(Map singeralbum, maps albumsong, char *songname, char *curP, char *curA) {
    // Pencarian lagu dalam struktur data albumsong
    int found = 0;  // Flag untuk menandakan apakah lagu ditemukan
    int idxp, idxa, idxl;

    for (idxp = 0; idxp < singeralbum.Count; idxp++) {
        for (idxa = 0; idxa < singeralbum.Elements[idxp].Value.Count; idxa++) {
            for (idxl = 0; idxl < albumsong.Elements[idxp].Elements[idxa].Value.Count; idxl++) {
                // Menggunakan strcmp untuk membandingkan string
                if (songname == albumsong.Elements[idxp].Elements[idxa].Value.Elements[idxl].TabWord) {
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

char* dash(Word currentsong){
    char *artist;
    artist=(char *)malloc(30*sizeof(char));
    wordToString(SplitWordLeftMark(currentsong),artist);
    char *album;
    album=(char *)malloc(30*sizeof(char));
    wordToString(SplitWordLeftMark(SplitWordMark(currentsong)),album);    
    char *lagu;
    lagu=(char *)malloc(30*sizeof(char));
    wordToString(SplitWordMark(SplitWordMark(currentsong)),lagu);
    char *hasil;
    hasil=(char *)malloc(50*sizeof(char));
    stringConcat(artist,"-",hasil);
    stringConcat(hasil,album,hasil);
    stringConcat(hasil,"-",hasil);
    stringConcat(hasil,lagu,hasil);
    return hasil;
}

// char* checkQueueInPlaylist(Queue *UrutanLagu, MapPlaylist *Playlist, maps *albumsong, Map *penyanyiAlbums) {
//     // Cek apakah semua lagu dalam queue berada dalam suatu playlist
//          for (int i = UrutanLagu->idxHead; i < UrutanLagu->idxTail; i++) {
//             char currsong[50];
//             int k = 0;

//             while (k < 50 && UrutanLagu->buffer[UrutanLagu->idxHead].TabWord[k] != '\0')
//             {
//                 currsong[k] = UrutanLagu->buffer[UrutanLagu->idxHead].TabWord[k];
//                 k++;
//             }
//             currsong[k] = '\0';
//             char currPen[50];
//             char currAlb[50];
//         carialbumpenyanyi(*penyanyiAlbums, *albumsong, currsong, currPen, currAlb);

//         boolean foundInPlaylist = false;

//         // Iterasi melalui playlist untuk mencari lagu
//         for (int j = 1; j <= LengthListDynamic(Playlist[0]); j++) {
//             if ((Playlist[0].A[j].TabWord) == currsong) {
//                 foundInPlaylist = true;
//                 break;
//             }
//         }

//         // Jika lagu tidak ditemukan dalam playlist, maka tidak semua lagu berada dalam playlist
//         if (!foundInPlaylist) {
//             return NULL;
//         }
//     }

//     // Jika semua lagu ditemukan dalam playlist, kembalikan nama playlist
//     return Playlist[0].A[0].TabWord;
// }
void displayStatus(StaticList *penyanyi, Map *penyanyiAlbums, maps *albumsong , Queue *UrutanLagu, MapPlaylist *Playlist, Word *currentSong)
{
    printf(">> STATUS;\n");
    // char* playlistName = checkQueueInPlaylist(UrutanLagu, Playlist, albumsong, penyanyiAlbums);

             
    // if (playlistName != NULL) {
    //     printf("\nCurrent Playlist: %s\n", playlistName);
    // }
    // else{
    //     printf("\0");
    // }
    printf("Now Playing : \n");
    // Cek apakah ada lagu yang sedang diputar
    if (IsCommandEqual(*currentSong,"-")|| IsCommandEqual(*currentSong,""))
    {
        printf("No songs have been played yet. Please search for a song to begin playback.\n");
        
    }
    else {
        printf("%s",dash(*currentSong));}

   
    printf("\nQueue:\n");
    if(isQueueEmpty(*UrutanLagu))
    {
        printf("Your queue is empty.\n");
    }
    else{
        int a = 1;
            for (int i = UrutanLagu->idxHead  ; i <= UrutanLagu->idxTail;i++){
            printf("%d. %s\n", a, dash(UrutanLagu->buffer[i]));
            a++;
            }
    }
             

}


