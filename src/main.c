#include "tambahan.h"
#include "boolean.h"
#include "start.h"
#include "help.h"
#include "load.h"
#include "quit.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    StaticList penyanyi;
    Map penyanyiAlbums;
    Map AlbumLagu;
    maps albumsong;
    Queue UrutanLagu;
    ArrayDin Playlist;
    Stack RiwayatLagu;
    LinierList LaguPlaylist;

    initializeList(&penyanyi);
    CreateEmptymap(&penyanyiAlbums);
    CreateEmptymap(&AlbumLagu);
    createmaps(&albumsong);
    CreateQueue(&UrutanLagu);
    CreateDynArray(&Playlist);
    CreateEmptyStack(&RiwayatLagu);
    CreateEmptyLinier(&LaguPlaylist);

    boolean saved = false;
    boolean endProgram = false;
    // char *command;
    // command = (char *) malloc (50 * sizeof(char));

    printf("    W   W  EEEEE  L      CCCC  OOO  M   M  EEEEE  !\n");
    printf("    W   W  E      L     C     O   O MM MM  E      !\n");
    printf("    W W W  EEEE   L     C     O   O M M M  EEEE   !\n");
    printf("    W W W  E      L     C     O   O M   M  E      \n");
    printf("     W W   EEEEE  LLLL   CCCC  OOO  M   M  EEEEE  !\n");
    printf("\n");
    printf("                                  PERINGATAN!!!\n");
    printf("======================================================================================\n");
    printf("PROGRAM AKAN ERROR ATAU BERHENTI KETIKA MENJALANKAN COMMAND YANG MEMILIKI KARAKTER '.'\n");
    printf("======================================================================================\n\n");
    printf("Selamat datang di WayangWave\n\n");
    printf("Jalankan command START atau LOAD <nama file> untuk membuka file.\n");
    printf("Jalankan command QUIT untuk keluar dari program.");

    while (endProgram == false)
    {
        printf("\nJalankan command HELP untuk melihat daftar commands yang tersedia.\n");
        printf("ENTER COMMAND: ");
        StartCommand();
        // inputString(0, command);
        // system("cls||clear");
        if (IsEmptymap(penyanyiAlbums))
        {
            if (IsCommandEqual(currentCommand, "START"))
            {
                start(&penyanyi, &penyanyiAlbums, &albumsong);
                // inputString(0, command);
            }
            else if (IsCommandEqual(currentCommand, "LOAD"))
            {
                char *inputfile;
                inputfile = (char *)malloc(30 * sizeof(char));
                ADVInput();
                // printf(currentWord.TabWord);
                // if (currentChar == '\n'){
                wordToString(currentCommand, inputfile);
                if (compareString(upper(inputfile), "LOAD") == false)
                {
                    load(inputfile, &penyanyi, &penyanyiAlbums, &albumsong, &UrutanLagu, &Playlist, &RiwayatLagu, &LaguPlaylist);
                }
                else
                {
                    printf("Command belum memiliki parameter. Silahkan input command sesuai format LOAD <filename .txt>\n");
                }
            }
            else if (IsCommandEqual(currentCommand, "QUIT"))
            {
                quit(&penyanyi, &penyanyiAlbums, &albumsong, &UrutanLagu, &Playlist, &RiwayatLagu, true);
                endProgram = true;
            }
            else if (IsCommandEqual(currentCommand, "HELP"))
            {
                showhelp1();
                // inputString(0, command);
            }
        }
        else
        {
            if (IsCommandEqual(currentCommand, "HELP"))
            {
                showhelp2();
                // inputString(0, command);
            }
            else if (IsCommandEqual(currentCommand, "QUIT"))
            {
                quit(&penyanyi, &penyanyiAlbums, &albumsong, &UrutanLagu, &Playlist, &RiwayatLagu, saved);
                endProgram = true;
            }
            else if (IsCommandEqual(currentCommand, "LIST DEFAULT"))
            {
                PrintPenyanyi(penyanyi);
                printf("\nIngin melihat album yang ada?(Y/N): ");
                // inputString(0, command)
                if (IsCommandEqual(currentCommand, "Y"))
                {
                    printf("Pilih penyanyi untuk melihat album mereka: ");
                    // inputString(0, command);
                }
                // else if (IsCommandEqual(currentCommand, "N"))
                // {
                //     *program berhenti*
                // }
                // PrintLagu()
            }
        }
    }
    return 0;
}