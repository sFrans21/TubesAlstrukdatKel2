#include "tambahan.h"
#include "boolean.h"
#include "start.h"
#include "help.h"
#include "load.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    StaticList penyanyi;
    Map penyanyiAlbums;
    maps albumsong;
    Queue UrutanLagu;
    ArrayDin Playlist;
    Stack RiwayatLagu;

    initializeList(&penyanyi);
    CreateEmptymap(&penyanyiAlbums);
    createmaps(&albumsong);
    CreateQueue(&UrutanLagu);
    CreateDynArray(&Playlist);
    CreateEmptyStack(&RiwayatLagu);

    boolean saved = false;
    boolean endProgram = false;
    char *command;
    command = (char *) malloc (50 * sizeof(char));

    printf("    W   W  EEEEE  L      CCCC  OOO  M   M  EEEEE  !\n");
    printf("    W   W  E      L     C     O   O MM MM  E      !\n");
    printf("    W W W  EEEE   L     C     O   O M M M  EEEE   !\n");
    printf("    W W W  E      L     C     O   O M   M  E      \n");
    printf("     W W   EEEEE  LLLL   CCCC  OOO  M   M  EEEEE  !\n");

    printf("                                  PERINGATAN!!!\n");
    printf("======================================================================================\n");
    printf("PROGRAM AKAN ERROR ATAU BERHENTI KETIKA MENJALANKAN COMMAND YANG MEMILIKI KARAKTER '.'\n");
    printf("======================================================================================\n\n");
    printf("Selamat datang di WayangWave\n\n");
    printf("Jalankan command START atau LOAD <nama file> untuk membuka file.\n");
    printf("Jalankan command QUIT untuk keluar dari program.");

    while (endProgram == false) {
        printf("\nJalankan command HELP untuk melihat daftar commands yang tersedia.");
        printf("\nENTER COMMAND: ");
        inputString(command,50);
        if (IsEmptymap(penyanyiAlbums)){
            if (compareString(upper(command), "START") == true) {
                    start(&penyanyi, &penyanyiAlbums, &albumsong);
            }
            else if (compareString(upper(command), "LOAD") == true){
                char *inputfile;
                inputfile = (char *) malloc (30 *sizeof(char));
                ADVLine();
                if (currentChar == '\n'){
                    wordToString(currentWord, inputfile);
                    if (compareString(upper(inputfile), "LOAD") == false){
                        load(inputfile, &penyanyi, &penyanyiAlbums, &albumsong, &UrutanLagu, &Playlist, &RiwayatLagu);
                    } else {
                        printf("Command belum memiliki parameter. Silahkan input command sesuai format LOAD <filename tanpa .txt>\n");
                    }
                }
            }
            else if (compareString(upper(command), "QUIT") == true) {
                //QUIT(&Games, &GamesQueue, &History, &Scoreboard, true);
                endProgram = true;
            }
            else if (compareString(upper(command), "HELP") == true) {
                showhelp1();
            }
        }

    }
    free(command);
    return 0;
}