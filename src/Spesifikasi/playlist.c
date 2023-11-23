#include "playlist.h"
#include <stdlib.h>
#include <stdio.h>

void CreatePlaylist (Word CPlaylist)
{
    int countKarakter = 0;
    printf("Masukkan nama playlist yang ingin di buat : ");
    StartWordMark();
    printf("\n");

    for ( int i = 0; i < currentWord.Length; i++){
        if (currentWord.TabWord[i] != BLANK){
            countKarakter++;
        }
    }

    if (countKarakter >= 3){
        CreateEmptyLinier.PlaylistLagu.Song;
        InsertLastDynamic (currentWord);
        printf("Playlist ");
        DisplayWord (currentWord);
        printf(" berhasil dibuat! \n");
        printf("\n Silahkan masukkan lagu - lagu artis terkini kesayangan Anda!\n");
    }
    else{
        printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silahkan coba lagi.\n");

    }

}  

void PlaylistAddSong(StaticList *penyanyi, Map *penyanyiAlbums, maps *albumsong ,DynamicList *DaftarPlaylist);
{
    if (!IsListEmptyDynamic){
        printf("Daftar Penyanyi :\n");
        for(int index = 0; index < LengthList(penyanyi); index ++){
            printf("\t&d", index+1);
            DisplayWord(GetLis)
        }
    }

}

void PlaylistAddAlbum(StaticList penyanyi, Map singeralbum, maps albumsong ,DynamicList *DaftarPlaylist);

void PlaylistSwap(DynamicList DaftarPlaylist, int idx1, int idx2);

void PlaylistRemove(DynamicList DaftarPlaylist);

void PlaylistDelete(DynamicList DaftarPlaylist);
