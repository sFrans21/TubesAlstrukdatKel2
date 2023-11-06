#include <stdio.h>
#include "start.h"

void StartWW(ArrayDin *ListPenyanyi, ArrayDin *ListAlbum, ArrayDin *ListLagu){
    char path[NMax];
    char *filename = "config.txt";
    stringConcat("../data/",filename,path);
    //printf("%s\n",path);

    STARTWORD(path);
    int nPenyanyi = WordToInt(currentWord);
    //nPenyanyi -= 10;
    //printf("%d\n" , nPenyanyi);
    char stringPenyanyi[NMax];
    for (int i = 1; i <= nPenyanyi; i++){
        char *namaPenyanyi = (char*) malloc (currentWord.Length * sizeof(char));
        //char *namaPenyanyi;
        ADVLine();
        int nAlbum = WordtoInt(currentWord);
        //printf("%d\n", nAlbum);
        //nAlbum -= 10;
        ADVWORD();
        wordToString(currentWord, stringPenyanyi);
        //printf("%s\n", stringPenyanyi);
        int j = 0;
        while (j <= currentWord.Length){
            namaPenyanyi[j] = stringPenyanyi[j];
            j++;
        }
        //namaPenyanyi[j] = '\0';
        InsertLast(ListPenyanyi, namaPenyanyi);
        printf("%s\n" , (*ListPenyanyi).A[i-1]);

        char stringAlbum[NMax];
        for (int k = 1; k <= nAlbum; k++){
            char *namaAlbum = (char*) malloc (currentWord.Length * sizeof(char));
            ADVLine();
            int nLagu = WordtoInt(currentWord);
            //printf("%d\n", nLagu);
            //nLagu -= 10;
            ADVWORD();
            wordToString(currentWord , stringAlbum);
            //printf("%s\n", stringAlbum);
            int l = 0;
            while (l <= currentWord.Length){
                namaAlbum[l] = stringAlbum[l];
                l++;
            }
            InsertLast(ListAlbum, stringAlbum);
            printf("%s\n" , (*ListAlbum).A[i-1]);

            char stringLagu[NMax];
            for (int m = 1; m <= nLagu; m++){
                char *namaLagu = (char*) malloc (currentWord.Length * sizeof(char));
                ADVLine();
                WordToString(currentWord, stringLagu);
                int n = 0;
                while (n <= currentWord.Length){
                    namaLagu[n] = stringLagu[n];
                    n++;
                }
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