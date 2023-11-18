#include <stdio.h>
#include <stdlib.h>
#include "load.h"
#include "tambahan.h"
#include "ADT/mesinkata.h"

void load(char *inputfile, StaticList *penyanyi, Map *penyanyiAlbums, maps *albumsong, Queue *UrutanLagu, ArrayDin *Playlist, Stack *RiwayatLagu){
    Set albums;
    Set songs;
    CreateEmptySet(&albums);
    CreateEmptySet(&songs);
    Map albumLagu;
    CreateEmptymap(&albumLagu);

    char *txt = ".txt";
    char *filename;
    char *directory;
    filename = (char *) malloc (25 * sizeof(char));
    directory = (char *) malloc (50 * sizeof(char));
    stringConcat(inputfile, txt, filename);
    stringConcat("../save/", filename, directory);

    FILE *open;
    open = fopen(directory, "r");
    if (open != NULL){
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
        char *Rlagu;
        for (int i = 1; i <= nRLagu; i++){
            ADVLine();
            Word RLagu;
            for (int j = 0; j < currentWord.Length; j++) {
                RLagu.TabWord[j] = currentWord.TabWord[j];
            }
            RLagu.Length = currentWord.Length;
            Push(RiwayatLagu, Rlagu);
            printf("%s\n", RLagu.TabWord);
            for (int b = 0; b < RLagu.Length; b++){
                RLagu.TabWord[b] = '\0';
            }
        }

        //ARRAYDIN PLAYLIST
        ADVLine();
        int nPlaylist = WordToInt(currentWord);
        printf("%d\n", nPlaylist);
        char stringPlaylist[NMax];
        for (int i = 1; i <= nPlaylist; i++){
            char *namaPlaylist = (char*) malloc (currentWord.Length * sizeof(char));
            ADVWord();
            int nPLagu = WordToInt(currentWord);
            printf("%d ", nPLagu);
            ADVLine();
            wordToString(currentWord, stringPlaylist);
            int j = 0;
            while (j <= currentWord.Length){
                namaPlaylist[j] = stringPlaylist[j];
                j++;
            }
            InsertLast(Playlist, namaPlaylist);
            printf("%s\n", ((*Playlist).A[i-1]));

            ArrayDin *LaguPlaylist;
            CreateDynArray(LaguPlaylist);
            char stringLaguPlaylist[NMax];
            for (int i = 1; i <= nPLagu; i++){
                char *namaPLagu = (char*) malloc (currentWord.Length * sizeof(char));
                ADVLine();
                wordToString(currentWord, stringLaguPlaylist);
                int j = 0;
                while (j <= currentWord.Length){
                    namaPLagu[j] = stringLaguPlaylist[j];
                    j++;
                }
                InsertLast(LaguPlaylist, namaPLagu);
                printf("%s\n", ((*LaguPlaylist).A[i-1]));
            }
        }
        printf("Save file berhasil dibaca. WayangWave berhasil dijalankan.\n");
    
    } else {
        printf("Save file tidak ditemukan. WayangWave gagal dijalankan.");
    }
}