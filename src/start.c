#include <stdio.h>
#include "start.h"
#include "tambahan.h"

void start(StaticList penyanyi, Map album, Map lagu)
{
    int jumlahPenyanyi, jumlahAlbum, jumlahLagu;
    //Word namaPenyanyi, namaAlbum, judulLagu;

    StartWordFile("cek.txt");
    jumlahPenyanyi = WordToInt(currentWord);
    printf("%d\n", jumlahPenyanyi);
    for (int i = 0; i < jumlahPenyanyi; i++) {
        AdvWord();
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
            jumlahLagu = WordToInt(currentWord);
            printf("%d\n", jumlahLagu);
            AdvWordFile();
            Word namaAlbum;
            //namaAlbum.Length = currentWord.Length;
            for (int j = 0; j < currentWord.Length; j++) {
                namaAlbum.TabWord[j] = currentWord.TabWord[j];
            }
            Insertmap(&album, namaPenyanyi, namaAlbum);
            printf("%s\n", namaAlbum.TabWord);
        
            for (int k=0; k<jumlahLagu; k++)
            {
                AdvWordFile();
                Word judulLagu;
                //judulLagu.Length = currentWord.Length;
                for (int j = 0; j < currentWord.Length; j++) {
                    judulLagu.TabWord[j] = currentWord.TabWord[j];
                }
                Insertmap(&lagu, namaAlbum, judulLagu);
                printf("%s\n", judulLagu.TabWord);
            }
        }
    }
}

int main (){
    StaticList penyanyi;
    Map album;
    Map lagu;
    start(penyanyi, album, lagu);
}