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
        inputString(0, input);
        if (compareString(upper(input), "N") == true){
            quit(penyanyi, penyanyiAlbums, albumsong, UrutanLagu, Playlist, RiwayatLagu, true);
        }
        else if (compareString(upper(input), "Y") == true){
            char *inputfile;
            inputfile = (char *) malloc (50 * sizeof(char));
            printf("\nSilahkan input nama file untuk disimpan (tanpa .txt): ");
            inputString(0, inputfile);
            //SAVE(Games, History, Scoreboard, inputfile);
            quit(penyanyi, penyanyiAlbums, albumsong, UrutanLagu, Playlist, RiwayatLagu, true);
        }
        else{
            printf("\nCommand tidak dapat diproses. Silahkan input command (Y/N).\n\n");
            quit(penyanyi, penyanyiAlbums, albumsong, UrutanLagu, Playlist, RiwayatLagu, false);
        }
    }
}