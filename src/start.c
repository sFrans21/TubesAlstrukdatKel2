#include <stdio.h>
#include "start.h"

void StartWW(ArrayDin *ListPenyanyi, ArrayDin *ListAlbum, ArrayDin *ListLagu){
    char path[NMax];
    char *filename = "config.txt";
    stringConcat("../data/",filename,path);
    printf("%s\n",path);

    STARTWORD(path);
    int nPenyanyi = WordToInt(currentWord);
    printf("%d\n" , nPenyanyi);
    nPenyanyi -= 10;

    char stringPenyanyi[NMax];
    for (int i = 1; i <= nPenyanyi; i++){
        ADVLine();
        int nAlbum = WordtoInt(currentWord);
        printf("%d\n", nAlbum);
        nAlbum -= 10;
        ADVWORD();
        wordToString(currentWord , stringPenyanyi);
        InsertLast(ListPenyanyi , stringPenyanyi);
        printf("%s\n" , (*ListPenyanyi).A[i-1]);

        char stringAlbum[NMax];
        for (int j = 1; j <= nAlbum; j++){
            ADVLine();
            int nLagu = WordtoInt(currentWord);
            printf("%d\n", nLagu);
            nLagu -= 10;
            ADVWORD();
            wordToString(currentWord , stringAlbum);
            InsertLast(ListAlbum, stringAlbum);
            printf("%s\n" , (*ListAlbum).A[i-1]);

            char stringLagu[NMax];
            for (int k = 1; k <= nLagu; k++){
                ADVLine();
                WordToString(currentWord, stringLagu);
                InsertLast(ListLagu, stringLagu);
                printf("%s\n", (*ListLagu).A[i-1]);
            }
        }
    }
    if(!IsEmpty(*ListPenyanyi)) 
    { 
        printf("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n"); 
    } else {
        printf("File konfigurasi kosong.\n");
    }
}


int main(){
    ArrayDin ListPenyanyi, ListAlbum, ListLagu;
    StartWW(&ListPenyanyi, &ListAlbum, &ListLagu);
}