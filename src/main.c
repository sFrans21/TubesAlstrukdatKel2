#include "tambahan.h"
#include "boolean.h"
#include "start.h"
#include "load.h"
#include <stdio.h>

int main()
{
    StaticList penyanyi;
    Map album;
    Map lagu;
    Queue UrutanLagu;
    ArrayDin Playlist;
    Stack RiwayatLagu;

    initializeList(&penyanyi);
    CreateEmptymap(&album);
    CreateEmptymap(&lagu);
    CreateQueue(&UrutanLagu);
    CreateDynArray(&Playlist);
    CreateEmptyStack(&RiwayatLagu);

    boolean compile = true;
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

    while (compile) {
        printf("\nJalankan command HELP untuk melihat daftar commands yang tersedia.");
        printf("\nENTER COMMAND: ");
        inputString(command);

        if (compareString(upper(command), "START") == true) {
            if (!endProgram){
                start(&penyanyi, &album, &lagu);
                compile = true;
            } else {
                printf("Command gagal\n");
            }
        }
        else if (compareString(upper(command), "LOAD") == true){
            if (!endProgram){
                char *filename;
                filename = (char *) malloc (30 *sizeof(char));
                ADVWord;
                if (currentChar == '\n'){
                    load(filename, &penyanyi, &album, &lagu, &UrutanLagu, &Playlist, &RiwayatLagu);
                }
            } else {
                printf("Command gagal\n");
            }
        }

    }
}