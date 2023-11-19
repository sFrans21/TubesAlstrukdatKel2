#include <stdio.h>
#include <stdlib.h>
#include "quit.h"
#include "tambahan.h"
#include "ADT/mesinkata.h"

void quit(StaticList *penyanyi, Map *penyanyiAlbums, maps *albumsong, Queue *UrutanLagu, ArrayDin *Playlist, Stack *RiwayatLagu, boolean saved){
    if (saved == true){
        printf("\nKamu keluar dari WayangWave.\nDadah ^_^/\n");
    }
    else{
        char *input;
        input = (char *) malloc (7 * sizeof(char));
        printf("Apakah kamu ingin menyimpan data sesi sekarang? (Y/N): \n");
        StartCommand();
        if (currentCommand.TabWord[0] == 'N'){
            quit(penyanyi, penyanyiAlbums, albumsong, UrutanLagu, Playlist, RiwayatLagu, true);
        }
        else if (currentCommand.TabWord[0] == 'Y'){
            char *inputfile;
            inputfile = (char *) malloc (50 * sizeof(char));
            printf("\nSilahkan input nama file untuk disimpan: ");
            StartWordInput();
            Word filename;
            filename.Length = currentWord.Length;

            int i;
            for (i=0; i<currentWord.Length; i++){
                filename.TabWord[i] = currentWord.TabWord[i];
            }
            //SAVE(Games, History, Scoreboard, inputfile);
            quit(penyanyi, penyanyiAlbums, albumsong, UrutanLagu, Playlist, RiwayatLagu, true);
        }
        else{
            printf("\nCommand tidak dapat diproses. Silahkan input command (Y/N).\n\n");
            quit(penyanyi, penyanyiAlbums, albumsong, UrutanLagu, Playlist, RiwayatLagu, false);
        }
    }
}