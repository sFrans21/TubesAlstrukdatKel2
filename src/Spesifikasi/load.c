#include <stdio.h>
#include <stdlib.h>
#include "load.h"
#include "../tambahan.h"
#include "../ADT/mesinkata.h"

void load(char *inputfile, StaticList *penyanyi, Map *penyanyiAlbums, maps *albumsong, Queue *UrutanLagu, DynamicList *Playlist, Stack *RiwayatLagu, LinierList *LaguPlaylist, Word *currentSong){
    Set albums;
    Set songs;
    CreateEmptySet(&albums);
    CreateEmptySet(&songs);
    Map albumLagu;
    CreateEmptymap(&albumLagu);

    char *directory;
    directory = (char *) malloc (50 * sizeof(char));
    stringConcat("../save/", inputfile, directory);

    FILE *open;
    open = fopen(directory, "r");
    if (open != NULL){
        fclose(open);
        StartWordFile(directory, 1);

        int jumlahPenyanyi;
        jumlahPenyanyi = WordToInt(currentWord);
        //printf("%d\n", jumlahPenyanyi);
        for (int i = 0; i < jumlahPenyanyi; i++) {
            ADVWord();
            int jumlahAlbum;
            jumlahAlbum = WordToInt(currentWord);
            //printf("%d ", jumlahAlbum);
            Word namaPenyanyi;
            ADVLine();
            // Membuat salinan dari currentWord ke namaPenyanyi
            for (int j = 0; j < currentWord.Length; j++) {
                namaPenyanyi.TabWord[j] = currentWord.TabWord[j];
            }
            namaPenyanyi.Length = currentWord.Length;
            // Mengirim namaPenyanyi ke setItem

            setItem(penyanyi, i, &namaPenyanyi);
            //printf("%s\n", (*penyanyi).items[i].TabWord);

            for (int z=0; z < jumlahAlbum; z++)
            {
                ADVWord();
                int jumlahLagu;
                jumlahLagu = WordToInt(currentWord);
                //printf("%d ", jumlahLagu);
                ADVLine();
                Word namaAlbum;
                for (int j = 0; j < currentWord.Length; j++) {
                    namaAlbum.TabWord[j] = currentWord.TabWord[j];
                }
                namaAlbum.Length = currentWord.Length;
                InsertSet(&albums, namaAlbum);
                //printf("%s\n", namaAlbum.TabWord);
            
                for (int k=0; k<jumlahLagu; k++)
                {
                    ADVLine();
                    Word judulLagu;
                    for (int j = 0; j < currentWord.Length; j++) {
                        judulLagu.TabWord[j] = currentWord.TabWord[j];
                    }
                    judulLagu.Length = currentWord.Length;
                    InsertSet(&songs, judulLagu);
                    //printf("%s\n", judulLagu.TabWord);
                    for (int b = 0; b < judulLagu.Length; b++){
                        judulLagu.TabWord[b] = '\0';
                    }
                }
                Insertmap(&albumLagu, namaAlbum, songs);
                for (int b = 0; b < namaAlbum.Length; b++){
                    namaAlbum.TabWord[b] = '\0';}   
                CreateEmptySet(&songs);
            }
            Insertmap(penyanyiAlbums, namaPenyanyi, albums);
            insertmaps(albumsong, albumLagu);
            CreateEmptymap(&albumLagu);
            CreateEmptySet(&albums);
            for (int b = 0; b < namaPenyanyi.Length; b++){
                namaPenyanyi.TabWord[b] = '\0';}
        }
        printf("Save file berhasil dibaca. WayangWave berhasil dijalankan.\n");

        // BACA CURRENTSONG
        ADVLine();
        for (int j = 0; j < currentWord.Length; j++) {
            (*currentSong).TabWord[j] = currentWord.TabWord[j];
        }
        (*currentSong).Length = currentWord.Length;
        printf("%s\n", (*currentSong).TabWord);

        // QUEUE
        ADVLine();
        int nQueue = WordToInt(currentWord);
        printf("%d\n", nQueue);
        for (int i = 1; i <= nQueue; i++){
            ADVLine();
            Word laguQueue;
            for (int j = 0; j < currentWord.Length; j++) {
                laguQueue.TabWord[j] = currentWord.TabWord[j];
            }
            laguQueue.Length = currentWord.Length;
            enqueue(UrutanLagu, laguQueue);
            printf("%s\n", laguQueue.TabWord);
            for (int b = 0; b < laguQueue.Length; b++){
                laguQueue.TabWord[b] = '\0';
            }
        }

        //STACK RIWAYAT LAGU
        ADVLine();
        int nRLagu = WordToInt(currentWord);
        printf("%d\n", nRLagu);
        for (int i = 1; i <= nRLagu; i++){
            ADVLine();
            Word RLagu;
            for (int j = 0; j < currentWord.Length; j++) {
                RLagu.TabWord[j] = currentWord.TabWord[j];
            }
            RLagu.Length = currentWord.Length;
            Push(RiwayatLagu, RLagu);
            printf("%s\n", RLagu.TabWord);
            for (int b = 0; b < RLagu.Length; b++){
                RLagu.TabWord[b] = '\0';
            }
        }
        (*RiwayatLagu) = ReverseStack(*RiwayatLagu);

        //LIST DINAMIS PLAYLIST
        ADVLine();
        int nPlaylist = WordToInt(currentWord);
        printf("%d\n", nPlaylist);
        for (int i = 1; i <= nPlaylist; i++){
            ADVWord();
            int nPLagu = WordToInt(currentWord);
            printf("%d ", nPLagu);
            ADVLine();
            Word namaPlaylist;
            for (int j = 0; j < currentWord.Length; j++) {
                namaPlaylist.TabWord[j] = currentWord.TabWord[j];
            }
            namaPlaylist.Length = currentWord.Length;
            InsertLastDynamic(Playlist, namaPlaylist);
            printf("%s\n", namaPlaylist.TabWord);
            for (int b = 0; b < namaPlaylist.Length; b++){
                namaPlaylist.TabWord[b] = '\0';
            }

            for (int k = 1; k <= nPLagu; k++){
                ADVLine();
                Word namaPLagu;
                for (int j = 0; j < currentWord.Length; j++) {
                    namaPLagu.TabWord[j] = currentWord.TabWord[j];
                }
                namaPLagu.Length = currentWord.Length;
                InsVLast(LaguPlaylist, namaPLagu);
                printf("%s\n", namaPLagu.TabWord);
                for (int b = 0; b < namaPLagu.Length; b++){
                    namaPLagu.TabWord[b] = '\0';
                }
            }
        }
    } else {
        printf("Save file tidak ditemukan. WayangWave gagal dijalankan.\n");
    }
}

/*int main() {
    char *inputfile;
    inputfile = (char *) malloc (30 *sizeof(char));
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

    StartCommand();
    if (isInputEqual(currentCommand, "LOAD")){
        ADVInput();
        wordToString(currentCommand, inputfile);
        if (compareString(upper(inputfile), "LOAD") == false){
            load(inputfile, &penyanyi, &penyanyiAlbums, &albumsong, &UrutanLagu, &Playlist, &RiwayatLagu, &LaguPlaylist);
        } else {
            printf("Command belum memiliki parameter. Silahkan input command sesuai format LOAD <filename.txt>\n");
        }
    }
}*/