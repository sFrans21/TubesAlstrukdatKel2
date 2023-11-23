#include "tambahan.h"
#include "boolean.h"
#include "Spesifikasi/start.h"
#include "Spesifikasi/help.h"
#include "Spesifikasi/load.h"
#include "Spesifikasi/quit.h"
//#include "Spesifikasi/status.h"
#include "Spesifikasi/list.h"
//#include "Spesifikasi/save.h"
//#include "Spesifikasi/play.h"
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

    printf("\n");
    printf("\n");
    printf("\033[1;36m         #######################################################################\033[0m\n");
    printf("\033[1;35m         [|                                                                   |]\033[0m\n");
    printf("\033[1;35m         [|                                                                   |]\033[0m\n");
    printf("\033[1;35m         [|         W   W  EEEEE  L      CCCC  OOO  M   M  EEEEE    !!        |]\033[0m\n");
    printf("\033[1;35m         [|         W   W  E      L     C     O   O MM MM  E        !!        |]\033[0m\n");
    printf("\033[1;35m         [|         W W W  EEEE   L     C     O   O M M M  EEEE     !!        |]\033[0m\n");
    printf("\033[1;35m         [|         W W W  E      L     C     O   O M   M  E                  |]\033[0m\n");
    printf("\033[1;35m         [|          W W   EEEEE  LLLL   CCCC  OOO  M   M  EEEEE    !!        |]\033[0m\n");
    printf("\033[1;35m         [|                                                                   |]\033[0m\n");
    printf("\033[1;35m         [|                                                                   |]\033[0m\n");
    printf("\033[1;36m         #######################################################################\033[0m\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\033[1;34m                                 PERINGATAN!!!\033[0m\n");
    printf("\033[1;36m======================================================================================\033[0m\n");
    printf("\033[1;34m        MASUKKAN COMMAND DENGAN HURUF KAPITAL DAN DIAKHIRI DENGAN KARAKTER';'         \033[0m\n");
    printf("\033[1;36m======================================================================================\033[0m\n\n\n");
    printf("\033[1;36m                   Selamat datang di WayangWave!\033[0m\n\n");
    printf("\033[0;36mJalankan command START atau LOAD <nama file> untuk membuka file.\033[0m\n");
    printf("\033[0;36mJalankan command QUIT untuk keluar dari program.\033[0m\n");

    while (endProgram == false)
    {
        printf("\033[1;36mJalankan command HELP untuk melihat daftar commands yang tersedia.\n");
        printf("\033[1;34m>>> ");
        StartCommand();
        char *inputfile;
        inputfile = (char *)malloc(30 * sizeof(char));
        if (IsEmptymap(penyanyiAlbums))
        {
            if (IsCommandEqual(currentCommand, "START"))
            {
                start(&penyanyi, &penyanyiAlbums, &albumsong);
            }
            else if (IsCommandEqual(currentCommand, "LOAD"))
            {
                ADVInput();
                wordToString(currentCommand, inputfile);
                if (compareString(upper(inputfile), "LOAD") == false)
                {
                    load(inputfile, &penyanyi, &penyanyiAlbums, &albumsong, &UrutanLagu, &Playlist, &RiwayatLagu, &LaguPlaylist);
                }
                else
                {
                    printf("\033[1;35mCommand belum memiliki parameter. Silahkan input command sesuai format LOAD <filename .txt>\n");
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
            }
            else
            {
                system("cls||clear");
                printf("C\033[1;35mommand tidak bisa dieksekusi!\n");
            }
        }
        else
        {
            if (IsCommandEqual(currentCommand, "HELP"))
            {
                showhelp2();
            }
            else if (IsCommandEqual(currentCommand, "STATUS"))
            {
                //displayStatus(&penyanyi, &penyanyiAlbums, &albumsong, &UrutanLagu, &Playlist);
            }
            else if (IsCommandEqual(currentCommand, "SAVE"))
            {
                ADVInput();
                wordToString(currentCommand, inputfile);
                if (compareString(upper(inputfile), "SAVE") == false)
                {
                    //save(inputfile, &penyanyi, &penyanyiAlbums, &albumsong, &UrutanLagu, &Playlist, &RiwayatLagu, &LaguPlaylist);
                }
                else
                {
                    printf("\033[1;35mCommand belum memiliki parameter. Silahkan input command sesuai format SAVE <filename .txt>\n");
                }
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
                    printf("\n\033[1;36mIngin melihat album yang ada?(Y/N): ");
                    StartCommand();
                    if (currentCommand.TabWord[0] == 'Y')
                    {
                        printf("\n\n\033[1;36mPilih penyanyi untuk melihat album mereka: ");
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
                                printf("\033[1;36mDaftar Album oleh %s :\n", e);
                                PrintAlbum(penyanyiAlbums, currentWord);

                                printf("\033[1;36mIngin melihat lagu yang ada?(Y/N): ");
                                StartCommand();
                                if (currentCommand.TabWord[0] == 'Y')
                                {
                                    printf("\n\n\033[1;36mPilih album untuk melihat lagu yang ada di album : ");
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
                                            printf("\033[1;36mDaftar Lagu di %s :\n", e);
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
                } else {
                    printf("Command tidak bisa dieksekusi!\n");
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
                    printf("\n\n\033[1;36mMasukkan Nama Penyanyi yang dipilih : ");
                    StartWordInput();
                    //int IdxPenyanyi = IdxKetemuPenyanyi(penyanyi, currentWord);
                    int IdxAlbum;
                    int IdxLagu;
                    for (int i = 0; i < penyanyi.itemCount; i++)
                    {

                        if (isEqual(currentWord, penyanyi.items[i]) == true)
                        {

                            int ketemu;
                            ketemu = i;
                            char *e;
                            e = (char *)malloc(30 * sizeof(char));
                            wordToString(currentWord, e);
                            printf("\033[1;36mDaftar Album oleh %s :\n", e);
                            PrintAlbum(penyanyiAlbums, currentWord);
                            printf("\n\n\033[1;36mMasukkan Nama Album yang dipilih : ");
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
                                    printf("\033[1;36mDaftar Lagu di album %s :\n", e);
                                    PrintLagu(albumsong, currentWord, ketemu);
                                    printf("\n");

                                    printf("\n\n\033[1;36mMasukkan ID Lagu yang dipilih : ");
                                    // Word nums;
                                    // int manynums = 0;
                                    StartWordInput();
                                    // char *g;
                                    // g = (char *)malloc(30 * sizeof(char));
                                    // wordToString(currentCommand, g);
                                    // int val = CharToInt(g);

                                    // kalo atas gabisa, pake ini
                                    // StartWordInput();
                                    char *g;
                                    g = (char *)malloc(30 * sizeof(char));
                                    wordToString(currentWord, g);
                                    int val = CharToInt(g);

                                    IdxAlbum = ketemu;
                                    IdxLagu = val - 1;
                                    //printf("\033[1;36mMemutar lagu “%s” oleh “%s”.", albumsong.Elements[IdxPenyanyi].Elements[IdxAlbum].Value.Elements[IdxLagu].TabWord, e);

                                    /*Hapusin riwayat lagu & queue lagu*/

                                    //CreateEmptyRiwayat(&History);
                                    //CreateQueueBELV(&UrutanLagu);
                                }
                            }
                        }
                    }
                }

                char *fes;
                fes = (char *)malloc(30 * sizeof(char));
                ADVInput();
                wordToString(currentCommand, fes);
                if (compareString(upper(fed), "PLAYLIST") == true)
                {
                    printf("\033[1;36mMasukkan ID Playlist: ");
                    StartWordInput();
                    char *k;
                    k = (char *)malloc(30 * sizeof(char));
                    wordToString(currentWord, k);
                    int valk = CharToInt(k);

                    //printf("\033[1;36mMemutar playlist “%s”.", Playlist.IsiPlaylist[valk - 1].judulPlaylist.TabWord);
                }
            } else {
                system("cls||clear");
                printf("Command tidak bisa dieksekusi!\n");
            }
        }
    }
    return 0;
}
