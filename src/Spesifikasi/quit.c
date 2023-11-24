#include <stdio.h>
#include <stdlib.h>
#include "quit.h"
#include "../tambahan.h"
#include "../ADT/mesinkata.h"
#include "save.h"

void quit(StaticList *penyanyi, Map *penyanyiAlbums, maps *albumsong, Queue *UrutanLagu, DynamicList *Playlist, MapPlaylist *PlaylistLagu, Stack *RiwayatLagu, LinierList *LaguPlaylist, Word *currentSong, boolean saved){
    if (saved == true){
        printf("\nKamu keluar dari WayangWave.\nDadah ^_^/\n");
    }
    else{
        char *input;
        input = (char *) malloc (7 * sizeof(char));
        printf("Apakah kamu ingin menyimpan data sesi sekarang? (Y/N): ");
        StartCommand();
        if (currentCommand.TabWord[0] == 'N'){
            quit(penyanyi, penyanyiAlbums, albumsong, UrutanLagu, Playlist, PlaylistLagu, RiwayatLagu, LaguPlaylist, currentSong, true);
        }
        else if (currentCommand.TabWord[0] == 'Y'){
            char *inputfile;
            inputfile = (char *) malloc (50 * sizeof(char));
            printf("\nSilahkan input nama file untuk disimpan: ");
            StartWordInput();
            wordToString(currentWord, inputfile);
            // Word filename;
            // filename.Length = currentWord.Length;

            // int i;
            // for (i=0; i<currentWord.Length; i++){
            //     filename.TabWord[i] = currentWord.TabWord[i];
            // }
            save(inputfile, penyanyi, penyanyiAlbums, albumsong, UrutanLagu, PlaylistLagu, RiwayatLagu, LaguPlaylist, currentSong);
            quit(penyanyi, penyanyiAlbums, albumsong, UrutanLagu, Playlist, PlaylistLagu, RiwayatLagu, LaguPlaylist, currentSong, true);
        }
        else{
            printf("\nCommand tidak dapat diproses. Silahkan input command (Y/N).\n\n");
            quit(penyanyi, penyanyiAlbums, albumsong, UrutanLagu, Playlist, PlaylistLagu, RiwayatLagu, LaguPlaylist, currentSong, false);
        }
    }
}