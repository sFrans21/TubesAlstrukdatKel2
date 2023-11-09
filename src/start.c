#include <stdio.h>
#include "start.h"
#include "tambahan.h"

void start(StaticList *penyanyi, Map *album, Map *lagu) {
    StartWordFile("cek.txt");
    int jumlahPenyanyi;
    jumlahPenyanyi = WordToInt(currentWord);
    printf("%d\n", jumlahPenyanyi);
    for (int i = 0; i < jumlahPenyanyi; i++) {
        ADVWord();
        int jumlahAlbum;
        jumlahAlbum = WordToInt(currentWord);
        printf("%d\n", jumlahAlbum);
        Word namaPenyanyi;
        ADVLine();
        // Membuat salinan dari currentWord ke namaPenyanyi
        for (int j = 0; j < currentWord.Length; j++) {
            namaPenyanyi.TabWord[j] = currentWord.TabWord[j];
        }
        namaPenyanyi.Length = currentWord.Length;
        // Mengirim namaPenyanyi ke setItem
        //namaPenyanyi = currentWord;
        //setItem(penyanyi, i, &namaPenyanyi);
        printf("%s\n", namaPenyanyi.TabWord);

        namaPenyanyi.Length = 0;
        namaPenyanyi.TabWord[0] = '\0';


        for (int z=0; z < jumlahAlbum; z++)
        {
            ADVWord();
            int jumlahLagu;
            jumlahLagu = WordToInt(currentWord);
            printf("%d\n", jumlahLagu);
            ADVLine();
            Word namaAlbum;
            for (int j = 0; j < currentWord.Length; j++) {
                namaAlbum.TabWord[j] = currentWord.TabWord[j];
            }
            namaAlbum.Length = currentWord.Length;
            Insertmap(album, namaPenyanyi, namaAlbum);
            printf("%s\n", namaAlbum.TabWord);
        
            for (int k=0; k<jumlahLagu; k++)
            {
                ADVLine();
                Word judulLagu;
                for (int j = 0; j < currentWord.Length; j++) {
                    judulLagu.TabWord[j] = currentWord.TabWord[j];
                }
                judulLagu.Length = currentWord.Length;
                Insertmap(lagu, namaAlbum, judulLagu);
                printf("%s\n", judulLagu.TabWord);
            }
        }
    }
}

int main (){
    StaticList penyanyi;
    Map album;
    Map lagu;
    start(&penyanyi, &album, &lagu);
}