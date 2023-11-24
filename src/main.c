#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tambahan.h"
#include "boolean.h"
#include "Tambahan/nyoba.h"

// ≻────────────────────────────────────────── ⋆✩⋆ ──────────────────────────────────────────≺

#include "Spesifikasi/start.h"
#include "Spesifikasi/help.h"
#include "Spesifikasi/load.h"
#include "Spesifikasi/quit.h"
#include "Spesifikasi/status.h"
#include "Spesifikasi/list.h"
#include "Spesifikasi/save.h"
#include "Spesifikasi/play.h"
#include "Spesifikasi/queue.h"
//#include "Spesifikasi/playlist.h"
// #include "Spesifikasi/playlist.h"
#include "Spesifikasi/song.h"

// ≻────────────────────────────────────────── ⋆✩⋆ ──────────────────────────────────────────≺

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
    Word currentSong;
    Word LaguAyeuna;
    MapPlaylist mapforplaylist;
    int duration;

    initializeList(&penyanyi);
    CreateEmptymap(&penyanyiAlbums);
    CreateEmptymap(&AlbumLagu);
    CreateEmptymapPlaylist(&mapforplaylist);
    createmaps(&albumsong);
    CreateQueue(&UrutanLagu);
    CreateEmptyDynamic(&Playlist);
    CreateEmptyStack(&RiwayatLagu);
    CreateEmptyLinier(&LaguPlaylist);

    boolean saved = false;
    boolean endProgram = false;

    welcome();

    while (endProgram == false)
    {
        printf("\033[1;36mJalankan command HELP untuk melihat daftar commands yang tersedia.\n");
        printf("\033[1;34m>>> ");
        StartCommand();
        char *inputfile;
        inputfile = (char *)malloc(30 * sizeof(char));

    // ≻────────────────────────────────────────── ⋆✩⋆ ──────────────────────────────────────────≺

        if (IsEmptymap(penyanyiAlbums))
        {
            if (IsCommandEqual(currentCommand, "START"))
            {
                start(&penyanyi, &penyanyiAlbums, &albumsong);
            }
    // ≻────────────────────────────────────────── ⋆✩⋆ ──────────────────────────────────────────≺
            else if (IsCommandEqual(currentCommand, "LOAD"))
            {
                ADVInput();
                wordToString(currentCommand, inputfile);
                if (compareString(upper(inputfile), "LOAD") == false)
                {
                    load(inputfile, &penyanyi, &penyanyiAlbums, &albumsong, &UrutanLagu, &Playlist, &RiwayatLagu, &LaguPlaylist, &currentSong);
                }
                else
                {
                    printf("\033[1;35mCommand belum memiliki parameter. Silahkan input command sesuai format LOAD <filename .txt>\n");
                }
            }

    // ≻────────────────────────────────────────── ⋆✩⋆ ──────────────────────────────────────────≺

            else if (IsCommandEqual(currentCommand, "QUIT"))
            {
                quit(&penyanyi, &penyanyiAlbums, &albumsong, &UrutanLagu, &Playlist, &mapforplaylist, &RiwayatLagu, &LaguPlaylist, &currentSong, true);
                endProgram = true;
            }

    // ≻────────────────────────────────────────── ⋆✩⋆ ──────────────────────────────────────────≺

            else if (IsCommandEqual(currentCommand, "HELP"))
            {
                showhelp1();
            }

    // ≻────────────────────────────────────────── ⋆✩⋆ ──────────────────────────────────────────≺
            else
            {
                system("cls||clear");
                printf("\033[1;35mCommand tidak bisa dieksekusi!\n");
            }
        }

    // ≻────────────────────────────────────────── ⋆✩⋆ ──────────────────────────────────────────≺

        else
        {
            if (IsCommandEqual(currentCommand, "HELP"))
            {
                showhelp2();
            }

    // ≻────────────────────────────────────────── ⋆✩⋆ ──────────────────────────────────────────≺

            else if (IsCommandEqual(currentCommand, "STATUS"))
            {
                displayStatus(&penyanyi, &penyanyiAlbums, &albumsong, &UrutanLagu, &mapforplaylist,&currentSong);
            }

    // ≻────────────────────────────────────────── ⋆✩⋆ ──────────────────────────────────────────≺

            else if (IsCommandEqual(currentCommand, "SAVE"))
            {
                ADVInput();
                wordToString(currentCommand, inputfile);
                if (compareString(upper(inputfile), "SAVE") == false)
                {
                    save(inputfile, &penyanyi, &penyanyiAlbums, &albumsong, &UrutanLagu, &mapforplaylist, &RiwayatLagu, &LaguPlaylist,&currentSong);
                }
                else
                {
                    printf("\033[1;35mCommand belum memiliki parameter. Silahkan input command sesuai format SAVE <filename .txt>\n");
                }
            }
    // ≻────────────────────────────────────────── ⋆✩⋆ ──────────────────────────────────────────≺

            else if (IsCommandEqual(currentCommand, "QUIT"))
            {
                quit(&penyanyi, &penyanyiAlbums, &albumsong, &UrutanLagu, &Playlist, &mapforplaylist, &RiwayatLagu, &LaguPlaylist, &currentSong, saved);
                endProgram = true;
            }

    // ≻────────────────────────────────────────── ⋆✩⋆ ──────────────────────────────────────────≺

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
                                printf("\n\033[1;36mDaftar Album oleh %s :\n", e);
                                PrintAlbum(penyanyiAlbums, currentWord);

                                printf("\n\033[1;36mIngin melihat lagu yang ada?(Y/N): ");
                                StartCommand();
                                if (currentCommand.TabWord[0] == 'Y')
                                {
                                    printf("\n\n\033[1;36mPilih album untuk melihat lagu yang ada di album : ");
                                    StartWordInput();
                                    for (int j = 0; j < penyanyiAlbums.Elements[ketemu].Value.Count; j++)
                                    {
                                        if (isEqual(currentWord, penyanyiAlbums.Elements[ketemu].Value.Elements[j]) == true)
                                        {
                                            int ketemulagi;
                                            ketemulagi = j;
                                            char *e;
                                            e = (char *)malloc(30 * sizeof(char));
                                            wordToString(currentWord, e);
                                            printf("\n\033[1;36mDaftar Lagu di %s :\n", e);
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
                else
                {
                    printf("Command tidak bisa dieksekusi!\n");
                }
            }

    // ≻────────────────────────────────────────── ⋆✩⋆ ──────────────────────────────────────────≺


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
                    int IdxPenyanyi = IdxKetemuPenyanyi(penyanyi, currentWord);
                    int IdxAlbum;
                    int IdxLagu;
                    int ketemu;
                    for (int i = 0; i < penyanyi.itemCount; i++)
                    {

                        if (isEqual(currentWord, penyanyi.items[i]) == true)
                        {

                            ketemu = i;
                            char *e;
                            e = (char *)malloc(30 * sizeof(char));
                            wordToString(currentWord, e);
                            printf("\n\033[1;36mDaftar Album oleh %s :\n", e);
                            PrintAlbum(penyanyiAlbums, currentWord);
                            printf("\n\n\033[1;36mMasukkan Nama Album yang dipilih : \n");
                            StartWordInput();

                            for (int j = 0; j < penyanyiAlbums.Elements[ketemu].Value.Count; j++)
                            {
                                if (isEqual(currentWord, penyanyiAlbums.Elements[ketemu].Value.Elements[j]) == true)
                                {
                                    int ketemulagi;
                                    ketemulagi = j;
                                    char *e;
                                    e = (char *)malloc(30 * sizeof(char));
                                    wordToString(currentWord, e);
                                    printf("\n\033[1;36mDaftar Lagu di album %s :\n", e);
                                    PrintLagu(albumsong, currentWord, ketemu);
                                    printf("\n");

                                    printf("\n\n\033[1;36mMasukkan ID Lagu yang dipilih : \n");
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
                                    int nomorlagu = WordToInt(currentWord);

                                    // printf("\nMemutar lagu %s oleh %s.\n", albumsong.Elements[IdxPenyanyi].Elements[IdxAlbum].Value.Elements[IdxLagu].TabWord, penyanyi.items[ketemu].TabWord);
                                    /*Set CurrentSong ke lagu pilihan saat ini*/
                                    Word Mark = {";", 1};
                                    Word Penyanyisaha = penyanyi.items[IdxPenyanyi];
                                    Word Albumsaha = penyanyiAlbums.Elements[IdxPenyanyi].Value.Elements[IdxAlbum];
                                    Word Lagunanaon = albumsong.Elements[IdxPenyanyi].Elements[IdxAlbum].Value.Elements[IdxLagu];

                                    Word Pilihan = ConcatWord(Penyanyisaha, Mark);
                                    Pilihan = ConcatWord(Pilihan, Albumsaha);
                                    Pilihan = ConcatWord(Pilihan, Mark);
                                    Pilihan = ConcatWord(Pilihan, Lagunanaon);

                                    currentSong = Pilihan;

                                    /*Hapusin riwayat lagu & queue lagu*/

                                    CreateEmptyStack(&RiwayatLagu);
                                    CreateQueue(&UrutanLagu);
                                    // CreateQueueBELV(&UrutanLagu);

                                    printf("\nMemutar lagu %s oleh %s.\n", albumsong.Elements[IdxPenyanyi].Elements[j].Value.Elements[IdxLagu].TabWord, penyanyi.items[ketemu].TabWord);
                                }
                            }
                        }
                    }
                }

                // char *fes;
                // fes = (char *)malloc(30 * sizeof(char));
                // ADVInput();
                // wordToString(currentCommand, fes);
                else if (compareString(upper(fed), "PLAYLIST") == true)
                {
                    printf("\n\033[1;36mMasukkan ID Playlist: ");
                    StartWordInput();
                    char *k;
                    k = (char *)malloc(30 * sizeof(char));
                    wordToString(currentWord, k);
                    int valk = CharToInt(k);
                    LaguAyeuna = SplitWordMark(SplitWordMark(currentSong));
                    // nambahin laguayeuna ke plalist elemen pertama
                    InsVLast(&LaguPlaylist, LaguAyeuna);
                    // Playlist.A[0] = LaguAyeuna;
                    // Playlist.Neff++;

                    // queue akan berisi semua lagu yang ada dalam playlist yang akan dimainkan
                    CreateQueue(&UrutanLagu);
                    int ruy = NbElmt(LaguPlaylist);
                    addressLinier cuy = First(LaguPlaylist);
                    for (int i = 0; i < ruy; i++)
                    {
                        enqueue(&UrutanLagu, Info(cuy));
                        cuy = Next(cuy);
                    }
                    // isi riwayat lagu sama dengan queue, tetapi dengan urutan yang di-reverse.

                    CreateEmptyStack(&RiwayatLagu);
                    addressLinier cey = First(LaguPlaylist);
                    while (cey != Nil)
                    {
                        Push(&RiwayatLagu, Info(cey));
                        cey = Next(cey);
                    }

                    RiwayatLagu = ReverseStack(RiwayatLagu);
                    printf("\n\033[1;36mMemutar playlist %s.\n", Playlist.A[valk - 1].TabWord);
                }
            }

    // ≻────────────────────────────────────────── ⋆✩⋆ ──────────────────────────────────────────≺
            else if(IsCommandEqual(currentCommand, "SONG"))
            {
                char *ppo;
                ADVInput();
                wordToString(currentCommand, ppo);
                if (compareString(upper(ppo), "NEXT") == true)
                {
                    SongNext(&penyanyi, &penyanyiAlbums,&albumsong,&RiwayatLagu, &UrutanLagu,&currentSong);
                }
                else if(compareString(upper(ppo), "PREV") == true)
                {
                    SongPrev(&penyanyi, &penyanyiAlbums,&albumsong,&RiwayatLagu, &UrutanLagu,&currentSong);
                }
            }
            else if(IsCommandEqual(currentCommand, "QUEUE"))
            {
                char *charcom;
                ADVInput();
                wordToString(currentCommand, charcom);
                if (compareString(upper(charcom), "SONG") == true)
                {
                    queuesong(penyanyi,penyanyiAlbums,albumsong,&UrutanLagu);
                    printf("Berhasil menambahkan lagu ke queue");
                }
                else if(compareString(upper(charcom), "REMOVE") == true)
                {
                    ADVInput();
                    int inp = WordToInt(currentCommand)-1;
                    queueremove(&UrutanLagu,inp);
                    printf("Berhasil menghapus lagu dari queue");
                }
                else if(compareString(upper(charcom), "SWAP") == true)
                {
                    ADVInput();
                    int inp1 = WordToInt(currentCommand)-1;
                    ADVInput();
                    int inp2 = WordToInt(currentCommand)-1;
                    queueswap(&UrutanLagu,inp1,inp2);
                    printf("Berhasil menukar urutan lagu");
                }
                else if(compareString(upper(charcom), "CLEAR") == true)
                {
                    queueclear(&UrutanLagu);
                    printf("Berhasil mengosongkan queue");
                }
                else if(compareString(upper(charcom), "PLAYLIST") == true)
                {
                    queueplaylist(mapforplaylist, &UrutanLagu);
                }

    // ≻────────────────────────────────────────── ⋆✩⋆ ──────────────────────────────────────────≺
            else if (IsCommandEqual(currentCommand, "PLAYLIST"))
            {
                char *pep;
                pep = (char *)malloc(30 * sizeof(char));
                ADVInput();
                wordToString(currentCommand, pep);
                if (compareString(upper(pep), "ADD") == true)
                {
                    char *pep2;
                    pep2 = (char *)malloc(30 * sizeof(char));
                    ADVInput();
                    wordToString(currentCommand, pep2);
                    // if (compareString(upper(pep), "SONG") == true)
                    // {
                    //     //PlaylistAddSong(&penyanyi,&penyanyiAlbums,&albumsong,&Playlist,&LaguPlaylist);
                    //     // PrintPenyanyi(penyanyi);
                    //     // printf("masukkan nama penyanyi yang dipilih: ");
                    //     // StartWordInput();
                    //     // int Idxsinger = IdxKetemuPenyanyi(penyanyi, currentWord);
                    //     // int IdexAlbum;
                    //     // int IdexLagu;
                    //     // int found;
                    // }
                    // if (compareString(upper(pep2), "ALBUM") == true)
                    // {

                    // }
                }

                // else if (compareString(upper(pep), "SWAP") == true)
                // {
                // }

                // else if (compareString(upper(pep), "REMOVE") == true)
                // {
                // }
                else if (compareString(upper(pep), "DELETE") == true)
                {
                    PrintPlaylist(Playlist);
                    printf("Masukkan ID playlist yang ingin dipilih :");
                    StartWordInput();
                    char *n;
                    n = (char *)malloc(30 * sizeof(char));
                    wordToString(currentWord, n);
                    int valk = CharToInt(n);
                    // aksi penghapusan
                    for (int i = 0; i < LengthListDynamic(Playlist); i++)
                    {
                        if (isEqual(currentWord, penyanyi.items[i]) == true)
                        {
                            penyanyi.items[i + 1] = penyanyi.items[i];
                            penyanyi.itemCount -= 1;
                            printf("Playlist ID %d dengan judul %s berhasil dihapus.", valk, Playlist.A[valk - 1].TabWord);
                        }
                        else
                        {
                            printf("Tidak ada playlist dengan ID %d dalam daftar playlist pengguna. Silakan coba lagi.", valk);
                        }
                    }
                }
            }
            else
            {
                system("cls||clear");
                printf("\nCommand tidak bisa dieksekusi!\n");
            }
            }
    }
    }
    return 0;
}
