#include <stdio.h>
#include "load.h"
#include "tambahan.h"
#include "ADT/mesinkata.h"

void load(char *filename, StaticList penyanyi, Map album, Map lagu, Queue *UrutanLagu, ArrayDin *Playlist, Stack *RiwayatLagu){
    StartWordFile("cek2.txt");
    int jumlahPenyanyi;
    jumlahPenyanyi = WordToInt(currentWord);
    printf("%d\n", jumlahPenyanyi);
    for (int i = 0; i < jumlahPenyanyi; i++) {
        AdvWord();
        int jumlahAlbum;
        jumlahAlbum = WordToInt(currentWord);
        printf("%d\n", jumlahAlbum);
        AdvWordFile();

        // Membuat salinan dari currentWord ke namaPenyanyi
        Word namaPenyanyi;
        for (int j = 0; j < currentWord.Length; j++) {
            namaPenyanyi.TabWord[j] = currentWord.TabWord[j];
        }
        namaPenyanyi.Length = currentWord.Length; 

        // Mengirim namaPenyanyi ke setItem
        setItem(&penyanyi, i, &namaPenyanyi);
        printf("%s\n", penyanyi.items[i].TabWord);

        for (int z=0; z < jumlahAlbum; z++)
        {
            AdvWord();
            int jumlahLagu;
            jumlahLagu = WordToInt(currentWord);
            printf("%d\n", jumlahLagu);
            AdvWordFile();
            Word namaAlbum;
            for (int j = 0; j < currentWord.Length; j++) {
                namaAlbum.TabWord[j] = currentWord.TabWord[j];
            }
            namaAlbum.Length = currentWord.Length;
            Insertmap(&album, namaPenyanyi, namaAlbum);
            printf("%s\n", namaAlbum.TabWord);
        
            for (int k=0; k<jumlahLagu; k++)
            {
                AdvWordFile();
                Word judulLagu;
                for (int j = 0; j < currentWord.Length; j++) {
                    judulLagu.TabWord[j] = currentWord.TabWord[j];
                }
                judulLagu.Length = currentWord.Length;
                Insertmap(&lagu, namaAlbum, judulLagu);
                printf("%s\n", judulLagu.TabWord);
            }
        }
    }
    /* QUEUE*/

    /* STACK RIWAYAT LAGU */
        AdvWordFile();
        int nRLagu = WordToInt(currentWord);
        char *Rlagu;
        for (int i = 1; i <= nRLagu; i++){
            AdvWordFile();
            Rlagu = WORDTOSTRING(currentWord);
            Push(RiwayatLagu, Rlagu);
        }
        (*RiwayatLagu) = ReverseStack(*RiwayatLagu);

        /* ARRAYDIN PLAYLIST */
        ADVLine();
        int nPlaylist = WordToInt(currentWord);
        char stringPlaylist[NMax];
        for (int i = 1; i <= nPlaylist; i++){
            char *namaPlaylist = (char*) malloc (currentWord.Length * sizeof(char));
            ADVLine();
            int nPLagu = WordToInt(currentWord);
            ADVWord();
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
}
