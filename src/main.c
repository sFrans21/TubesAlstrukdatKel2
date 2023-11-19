#include "tambahan.h"
#include "boolean.h"
#include "start.h"
#include "help.h"
#include "load.h"
#include "quit.h"
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
    LinierList LaguPlaylist;

    initializeList(&penyanyi);
    CreateEmptymap(&penyanyiAlbums);
    createmaps(&albumsong);
    CreateQueue(&UrutanLagu);
    CreateDynArray(&Playlist);
    CreateEmptyStack(&RiwayatLagu);
    CreateEmptyLinier(&LaguPlaylist);

    boolean saved = false;
    boolean endProgram = false;
<<<<<<< Updated upstream
    //char *command;
    //command = (char *) malloc (50 * sizeof(char));
=======
<<<<<<< HEAD
    char *command;
    command = (char *)malloc(50 * sizeof(char));
=======
    //char *command;
    //command = (char *) malloc (50 * sizeof(char));
>>>>>>> 3f81e297c46e2c6214bab6264c48ca727ded0f88
>>>>>>> Stashed changes

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

<<<<<<< Updated upstream
=======
<<<<<<< HEAD
    while (endProgram == false)
    {
        printf("\nJalankan command HELP untuk melihat daftar commands yang tersedia.");
        printf("\nENTER COMMAND: ");
        inputString(0, command);
        // system("cls||clear");
        if (IsEmptymap(penyanyiAlbums))
        {
            if (compareString(upper(command), "START") == true)
            {
=======
>>>>>>> Stashed changes
    while (endProgram == false) {
        printf("\nJalankan command HELP untuk melihat daftar commands yang tersedia.\n");
        printf("ENTER COMMAND: ");
        StartCommand();
        // inputString(0, command);
        //system("cls||clear");
        if (IsEmptymap(penyanyiAlbums)){
            if (IsCommandEqual(currentCommand, "START")) {
<<<<<<< Updated upstream
                start(&penyanyi, &penyanyiAlbums, &albumsong);
                //inputString(0, command);
            }
            else if (IsCommandEqual(currentCommand, "LOAD")){
=======
>>>>>>> 3f81e297c46e2c6214bab6264c48ca727ded0f88
                start(&penyanyi, &penyanyiAlbums, &albumsong);
                //inputString(0, command);
            }
<<<<<<< HEAD
            else if (compareString(upper(command), "LOAD") == true)
            {
=======
            else if (IsCommandEqual(currentCommand, "LOAD")){
>>>>>>> 3f81e297c46e2c6214bab6264c48ca727ded0f88
>>>>>>> Stashed changes
                char *inputfile;
                inputfile = (char *)malloc(30 * sizeof(char));
                ADVInput();
<<<<<<< Updated upstream
=======
<<<<<<< HEAD
                // printf(currentWord.TabWord);
                // if (currentChar == '\n'){
                wordToString(currentWord, inputfile);
                if (compareString(upper(inputfile), "LOAD") == false)
                {
                    load(inputfile, &penyanyi, &penyanyiAlbums, &albumsong, &UrutanLagu, &Playlist, &RiwayatLagu);
                }
                else
                {
=======
>>>>>>> Stashed changes
                //if (currentChar == '\n'){
                //printf(currentCommand.TabWord);
                wordToString(currentCommand, inputfile);
                //printf("%s\n", inputfile);
                if (compareString(upper(inputfile), "LOAD") == false){
                    load(inputfile, &penyanyi, &penyanyiAlbums, &albumsong, &UrutanLagu, &Playlist, &RiwayatLagu, &LaguPlaylist);
                } else {
>>>>>>> 3f81e297c46e2c6214bab6264c48ca727ded0f88
                    printf("Command belum memiliki parameter. Silahkan input command sesuai format LOAD <filename .txt>\n");
                }
                //inputString(0, command);
            }
<<<<<<< Updated upstream
            else if (IsCommandEqual(currentCommand, "QUIT")) {
                quit(&penyanyi, &penyanyiAlbums, &albumsong, &UrutanLagu, &Playlist, &RiwayatLagu, true);
                endProgram = true;
            }
            else if (IsCommandEqual(currentCommand, "HELP")) {
                showhelp1();
                //inputString(0, command);
            }
        } else {
            if (IsCommandEqual(currentCommand, "HELP")) {
                showhelp2();
                //inputString(0, command);
            } else if (IsCommandEqual(currentCommand, "QUIT")) {
=======
<<<<<<< HEAD
            else if (compareString(upper(command), "QUIT") == true)
            {
                quit(&penyanyi, &penyanyiAlbums, &albumsong, &UrutanLagu, &Playlist, &RiwayatLagu, true);
                endProgram = true;
            }
            else if (compareString(upper(command), "HELP") == true)
            {
=======
            else if (IsCommandEqual(currentCommand, "QUIT")) {
                quit(&penyanyi, &penyanyiAlbums, &albumsong, &UrutanLagu, &Playlist, &RiwayatLagu, true);
                endProgram = true;
            }
            else if (IsCommandEqual(currentCommand, "HELP")) {
>>>>>>> 3f81e297c46e2c6214bab6264c48ca727ded0f88
                showhelp1();
                //inputString(0, command);
            }
<<<<<<< HEAD
        }
        else
        {
            if (compareString(upper(command), "HELP") == true)
            {
                showhelp2();
            }
            else if (compareString(upper(command), "QUIT") == true)
            {
=======
        } else {
            if (IsCommandEqual(currentCommand, "HELP")) {
                showhelp2();
                //inputString(0, command);
            } else if (IsCommandEqual(currentCommand, "QUIT")) {
>>>>>>> 3f81e297c46e2c6214bab6264c48ca727ded0f88
>>>>>>> Stashed changes
                quit(&penyanyi, &penyanyiAlbums, &albumsong, &UrutanLagu, &Playlist, &RiwayatLagu, saved);
                endProgram = true;
            }
        }
    }
    return 0;
}