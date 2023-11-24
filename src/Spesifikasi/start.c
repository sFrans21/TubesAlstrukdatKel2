#include <stdio.h>
#include "start.h"
#include "../tambahan.h"
#include "../Tambahan/nyoba.h"

void start(StaticList *penyanyi, Map *penyanyiAlbums, maps *albumsong)
{
    initializeList(penyanyi);
    CreateEmptymap(penyanyiAlbums);
    createmaps(albumsong);
    Set albums;
    Set songs;
    CreateEmptySet(&albums);
    CreateEmptySet(&songs);
    Map albumLagu;
    CreateEmptymap(&albumLagu);
    char path[NMax];
    char *filename = "config.txt";
    stringConcat("../save/", filename, path);
    StartWordFile(path, 1);

    starting();

    int jumlahPenyanyi;
    jumlahPenyanyi = WordToInt(currentWord);
    // printf("%d\n", jumlahPenyanyi);
    for (int i = 0; i < jumlahPenyanyi; i++)
    {
        ADVWord();
        int jumlahAlbum;
        jumlahAlbum = WordToInt(currentWord);
        // printf("%d ", jumlahAlbum);
        Word namaPenyanyi;
        ADVLine();
        // Membuat salinan dari currentWord ke namaPenyanyi
        for (int j = 0; j < currentWord.Length; j++)
        {
            namaPenyanyi.TabWord[j] = currentWord.TabWord[j];
        }
        namaPenyanyi.Length = currentWord.Length;
        // Mengirim namaPenyanyi ke setItem

        setItem(penyanyi, i, &namaPenyanyi);
        // printf("%s\n", (*penyanyi).items[i].TabWord);

        for (int z = 0; z < jumlahAlbum; z++)
        {
            ADVWord();
            int jumlahLagu;
            jumlahLagu = WordToInt(currentWord);
            // printf("%d ", jumlahLagu);
            ADVLine();
            Word namaAlbum;
            for (int j = 0; j < currentWord.Length; j++)
            {
                namaAlbum.TabWord[j] = currentWord.TabWord[j];
            }
            namaAlbum.Length = currentWord.Length;
            InsertSet(&albums, namaAlbum);
            // printf("%s\n", namaAlbum.TabWord);

            for (int k = 0; k < jumlahLagu; k++)
            {
                ADVLine();
                Word judulLagu;
                for (int j = 0; j < currentWord.Length; j++)
                {
                    judulLagu.TabWord[j] = currentWord.TabWord[j];
                }
                judulLagu.Length = currentWord.Length;
                InsertSet(&songs, judulLagu);
                //printf("%s\n", judulLagu.TabWord);
                for (int b = 0; b < judulLagu.Length; b++)
                {
                    judulLagu.TabWord[b] = '\0';
                }
            }
            Insertmap(&albumLagu, namaAlbum, songs);
            for (int b = 0; b < namaAlbum.Length; b++)
            {
                namaAlbum.TabWord[b] = '\0';
            }
            CreateEmptySet(&songs);
        }
        Insertmap(penyanyiAlbums, namaPenyanyi, albums);
        insertmaps(albumsong, albumLagu);
        CreateEmptymap(&albumLagu);
        CreateEmptySet(&albums);
        for (int b = 0; b < namaPenyanyi.Length; b++)
        {
            namaPenyanyi.TabWord[b] = '\0';
        }
    }

    printf("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n");
}
// printf("%s", penyanyiAlbums->Elements[1].Value.Elements[0].TabWord);
// }
// void queuesong(StaticList penyanyi, Map singeralbum, maps albumsong, Queue *kiw){
//     int idxp;
//     int idxa;
//     printf("Daftar Penyanyi : \n");
//     for(int i=0; i<penyanyi.itemCount; i++){
//          printf("   %d. %s\n", i+1, (penyanyi).items[i].TabWord);
//      }
//     printf("Masukkan Nama Penyanyi : ");
//     StartWordInput();
//     // printf("%d\n", penyanyi.itemCount);
//     // printf("%s\n", (penyanyi).items[1].TabWord);
//     // printf("%d\n", currentWord.Length);
//     // for (int i = 0; i < currentWord.Length; i++)
//     // {
//     //     printf("%c", currentWord.TabWord[i]);
//     // }
//     // printf("%d\n", penyanyi.items[0].Length);
//     for(int i=0; i<penyanyi.itemCount;i++)
//      {if (isEqual(currentWord,(penyanyi).items[i]))
//          {idxp=i;}
//      }
//     printf("Daftar Album oleh %s : \n", (penyanyi).items[idxp].TabWord);
//     for (int i=0;i<singeralbum.Elements[idxp].Value.Count;i++){
//          printf("   %d. %s\n", i+1,(singeralbum.Elements[idxp].Value.Elements[i].TabWord));}

//     printf("Masukkan Nama Album : ");
//     StartWordInput();
//     // printf("%d\n", albumsong.Elements[idxp].Elements[0].Key.Length);
//     // for (int i = 0; i < albumsong.Elements[idxp].Elements[0].Key.Length; i++)
//     // {
//     //     printf("%d : %c\n", i, albumsong.Elements[idxp].Elements[0].Key.TabWord[i]);
//     // }

//     // printf("%s\n", albumsong.Elements[idxp].Elements[0].Key.TabWord);

//     // printf("%d\n", currentWord.Length);
//     // for (int i = 0; i < currentWord.Length; i++)
//     // {
//     //     printf("%c", currentWord.TabWord[i]);
//     // }
//     // printf("\n");
//     // printf(".");
//     // printf("%d", albumsong.Elements[idxp].Elements[2].Key.Length);
//     for (int i=0;i<albumsong.Elements[idxp].Count;i++){
//         if (isEqual(currentWord, albumsong.Elements[idxp].Elements[i].Key)){
//             idxa = i;
//          }
//      }
//     printf("Daftar Lagu Album %s oleh %s : \n", albumsong.Elements[idxp].Elements[idxa].Key.TabWord, penyanyi.items[idxp].TabWord );
//     for(int i=0;i<albumsong.Elements[idxp].Elements[idxa].Value.Count;i++){
//         printf("    %d. %s \n", i+1, albumsong.Elements[idxp].Elements[idxa].Value.Elements[i].TabWord);
//     }
//     printf("Masukkan ID lagu yang dipilih : ");
//     StartWordInput();
//     int idxl = WordToInt(currentWord)-1;
//     enqueue(kiw, albumsong.Elements[idxp].Elements[idxa].Value.Elements[idxl]);
//     printf("Berhasil menambahkan lagu \"%s\" oleh \"%s\" ke queue.\n",albumsong.Elements[idxp].Elements[idxa].Value.Elements[idxl].TabWord,  (penyanyi).items[idxp].TabWord);
// }

// void queueswap(Queue *kiw, int idx1, int idx2){
//     Word temp;
//     temp = kiw->buffer[idx1];
//     kiw->buffer[idx1]=kiw->buffer[idx2];
//     kiw->buffer[idx2]=temp;
// }

// void queueremove(Queue *kiw, int i)
// {
// 	int j;
// 	for (j = i ; j < kiw->idxTail ; j++)
// 	{
// 		kiw->buffer[j] = kiw->buffer[j+1];
// 	}

// 	kiw->idxTail--;
// }

// void  queueclear(Queue *kiw){
//     CreateQueue(kiw);
// }

// int main (){
//     StaticList penyanyi;
//     Map penyanyiAlbums;
//     maps albumLagu;
//     Queue kiw;
//     CreateQueue(&kiw);
//     initializeList(&penyanyi);
//     CreateEmptymap(&penyanyiAlbums);
//     createmaps(&albumLagu);
//     start(&penyanyi, &penyanyiAlbums, &albumLagu);
//     queuesong(penyanyi, penyanyiAlbums, albumLagu, &kiw);
//     queuesong(penyanyi, penyanyiAlbums, albumLagu, &kiw);
//     displayQueue(kiw);
//     queueswap(&kiw, 0, 1);
//     displayQueue(kiw);
//     queueremove(&kiw, 0);
//     displayQueue(kiw);
//     queueclear(&kiw);
//     displayQueue(kiw);
// }