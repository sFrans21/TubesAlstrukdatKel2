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
    DynamicList Playlist;
    Stack RiwayatLagu;
    LinierList LaguPlaylist;

    initializeList(&penyanyi);
    CreateEmptymap(&penyanyiAlbums);
    CreateEmptymap(&AlbumLagu);
    createmaps(&albumsong);
    CreateQueue(&UrutanLagu);
    CreateEmptyDynamic(&Playlist);
    CreateEmptyStack(&RiwayatLagu);
    CreateEmptyLinier(&LaguPlaylist);

    boolean saved = false;
    boolean endProgram = false;
    // char *command;
    // command = (char *) malloc (50 * sizeof(char));

    printf("\033[1;32m    W   W  EEEEE  L      CCCC  OOO  M   M  EEEEE  !\033[0m\n");
    printf("\033[1;32m    W   W  E      L     C     O   O MM MM  E      !\033[0m\n");
    printf("\033[1;32m    W W W  EEEE   L     C     O   O M M M  EEEE   !\033[0m\n");
    printf("\033[1;32m    W W W  E      L     C     O   O M   M  E      \033[0m\n");
    printf("\033[1;32m     W W   EEEEE  LLLL   CCCC  OOO  M   M  EEEEE  !\033[0m\n");
    printf("\n");
    printf("\033[1;33m                                 PERINGATAN!!!\033[0m\n");
    printf("\033[1;32m======================================================================================\033[0m\n");
    printf("\033[1;33m          MASUKKAN COMMAND MENGGUNAKAN HURUF KAPITAL DAN DIAKHIRI DENGAN ';'\033[0m\n");
    printf("\033[1;32m======================================================================================\033[0m\n\n\n");
    printf("\033[1;32m                    Selamat datang di WayangWave!\033[0m\n\n");
    printf("\033[0;32mJalankan command START atau LOAD <filename.txt> untuk membuka file.\033[0m\n");
    printf("\033[0;32mJalankan command QUIT untuk keluar dari program.\033[0m\n");

    while (endProgram == false)
    {
        printf("\nJalankan command HELP untuk melihat daftar commands yang tersedia.\n");
        printf(">>> ");
        StartCommand();
        if (IsEmptymap(penyanyiAlbums))
        {
            if (IsCommandEqual(currentCommand, "START"))
            {
                start(&penyanyi, &penyanyiAlbums, &albumsong);
            }
            else if (IsCommandEqual(currentCommand, "LOAD"))
            {
                char *inputfile;
                inputfile = (char *)malloc(30 * sizeof(char));
                ADVInput();
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
            } else {
                printf("Command tidak bisa dieksekusi!\n");
            }
        }
        else
        {
            if (IsCommandEqual(currentCommand, "HELP"))
            {
                showhelp2();
            }
            else if (IsCommandEqual(currentCommand, "QUIT"))
            {
                quit(&penyanyi, &penyanyiAlbums, &albumsong, &UrutanLagu, &Playlist, &RiwayatLagu, saved);
                endProgram = true;
            }
            else if (IsCommandEqual(currentCommand, "LIST"))
            {
                char *def;
                def = (char *)malloc(30 * sizeof(char));
                ADVInput();
                wordToString(currentCommand, def);
                if (compareString(upper(def), "DEFAULT") == true)
                {
                    PrintPenyanyi(penyanyi);
                    printf("\nIngin melihat album yang ada?(Y/N): ");
                    StartCommand();
                    if (currentCommand.TabWord[0] == 'Y')
                    {
                        printf("Pilih penyanyi untuk melihat album mereka: ");
                        StartWordInput();
                        for (int i = 0; i < penyanyi.itemCount; i++)
                        {

                            if (isEqual(currentWord, penyanyi.items[i]) == true)
                            {
                                int ketemu;
                                ketemu = i;
                                char *e;
                                e = (char *)malloc(30 * sizeof(char));
                                wordToString(currentWord, e);
                                printf("Daftar Album oleh %s :\n", e);
                                PrintAlbum(penyanyiAlbums, currentWord);

                                printf("Ingin melihat lagu yang ada?(Y/N): ");
                                StartCommand();
                                if (currentCommand.TabWord[0] == 'Y')
                                {
                                    printf("Pilih album untuk melihat lagu yang ada di album : ");
                                    StartWordInput();
                                    for (int j = 0; j < penyanyiAlbums.Elements[ketemu].Value.Count; j++)
                                    {
                                        if (isEqual(currentWord, penyanyiAlbums.Elements[ketemu].Value.Elements[j]) == true)
                                        {
                                            // int ketemulagi;
                                            // ketemulagi = j;
                                            char *e;
                                            e = (char *)malloc(30 * sizeof(char));
                                            wordToString(currentWord, e);
                                            printf("Daftar Lagu di %s :\n", e);
                                            PrintLagu(albumsong, currentWord, ketemu);
                                        }
                                    }
                                }
                            }
                            //     printf("Ingin melihat lagu yang ada?(Y/N): \n");
                            //     StartWordInput();
                            //     if (currentWord.TabWord[0] == 'Y')
                            //     {
                            //         printf("Pilih album untuk melihat lagu yang ada di album : \n");
                            //         StartWordInput();
                            //         for (int j = 0; j < penyanyiAlbums.Elements[].Value.Count; j++)
                            //         {
                            //             if (isEqual(currentWord, penyanyiAlbums.Elements[].Value.Elements[j]) == true)
                            //             {
                            //                 int ketemu;
                            //                 ketemu = i;
                            //                 char *e;
                            //                 e = (char *)malloc(30 * sizeof(char));
                            //                 wordToString(currentWord, e);
                            //                 printf("Daftar Album oleh %s :\n", e);
                            //                 PrintAlbum(penyanyiAlbums, currentWord);
                            //             }
                            //         }
                            //     }
                            // }
                        }
                    }
                    // else if (IsCommandEqual(currentCommand, "N"))
                    // {
                    //     *program berhenti*
                    // }
                    // PrintLagu()
                    ////////////////////////////////////////////////////////*KALO ERROR APUS DARI SINI.*////////////////////////////////////////////////////
                }
                else if (compareString(upper(def), "PLAYLIST") == true)
                {
                    PrintPlaylist(Playlist); // inshaallah ga error
                }
            }
            else if (IsCommandEqual(currentCommand, "PLAY"))
            {
                char *fed;
                fed = (char *)malloc(30 * sizeof(char));
                ADVInput();
                wordToString(currentCommand, fed);
                if (compareString(upper(fed), "SONG") == true)
                {
                    PrintPenyanyi(penyanyi);
                    printf("Masukkan Nama Penyanyi yang dipilih : ");
                    StartWordInput();
                    for (int i = 0; i < penyanyi.itemCount; i++)
                    {

                        if (isEqual(currentWord, penyanyi.items[i]) == true)
                        {
                            int ketemu;
                            ketemu = i;
                            char *e;
                            e = (char *)malloc(30 * sizeof(char));
                            wordToString(currentWord, e);
                            printf("Daftar Album oleh %s :\n", e);
                            PrintAlbum(penyanyiAlbums, currentWord);

                            printf("Masukkan Nama Album yang dipilih : ");
                            StartWordInput();
                            for (int j = 0; j < penyanyiAlbums.Elements[ketemu].Value.Count; j++)
                            {
                                if (isEqual(currentWord, penyanyiAlbums.Elements[ketemu].Value.Elements[j]) == true)
                                {
                                    // int ketemulagi;
                                    // ketemulagi = j;
                                    char *e;
                                    e = (char *)malloc(30 * sizeof(char));
                                    wordToString(currentWord, e);
                                    printf("Daftar Lagu di album %s :\n", e);
                                    PrintLagu(albumsong, currentWord, ketemu);
                                    printf("\n");

                                    printf("Masukkan ID Lagu yang dipilih : ");
                                    // Word nums;
                                    // int manynums = 0;
                                    StartCommand();
                                    // while (!EndWord)
                                    // {
                                    //     manynums++;
                                    //     ADVWord;
                                    // }

                                    // if (IsCommandEqual(currentCommand, "1"))
                                    // {
                                    //     M.Elements[i].Elements[when].Value.Elements[e].TabWord
                                    //                                     }
                                    // else if(IsCommandEqual(currentCommand, "1")
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}