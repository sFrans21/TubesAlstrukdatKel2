#include <stdio.h>
#include <stdlib.h>
#include "save.h"
#include "status.h"
#include "../tambahan.h"

void stringConcat(char str1[], char str2[], char *output)
{
    int i = 0, j = 0;
    while (str1[i] != '\0')
    {
        output[i] = str1[i];
        i++;
    }

    while (str2[j] != '\0')
    {
        output[i] = str2[j];
        j++;
        i++;
    }
    output[i] = '\0';
}
boolean IsListEmptyDynamic(DynamicList list)
{
    return (list.Neff == 0);
}

int LengthListDynamic(DynamicList list)
{
    return (list.Neff);
}

boolean IsEmptyStack(Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
      return Top(S) == Undef;
}
void carialbumpenyanyi(Map singeralbum, maps albumsong, char *songname, char *curP, char *curA) {
    // Pencarian lagu dalam struktur data albumsong
    int found = 0;  // Flag untuk menandakan apakah lagu ditemukan
    int idxp, idxa, idxl;

    for (idxp = 0; idxp < singeralbum.Count; idxp++) {
        for (idxa = 0; idxa < singeralbum.Elements[idxp].Value.Count; idxa++) {
            for (idxl = 0; idxl < albumsong.Elements[idxp].Elements[idxa].Value.Count; idxl++) {
                // Menggunakan strcmp untuk membandingkan string
                if (songname != albumsong.Elements[idxp].Elements[idxa].Value.Elements[idxl].TabWord) {
                    found = 1;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        if (found) {
            break;
        }
    }

    // Menyalin hasil pencarian ke variabel curP dan curA
    if (found) {
        curP = singeralbum.Elements[idxp].Key.TabWord;
        curA = singeralbum.Elements[idxp].Value.Elements[idxa].TabWord;
    }
}
boolean isQueueEmpty(Queue q){
/* Mengirim true jika q kosong: lihat definisi di atas */
    return ((IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF));
}

void save(char *filename, StaticList *penyanyi, Map *penyanyiAlbums, maps *albumsong, Queue *UrutanLagu, DynamicList *Playlist, Stack *RiwayatLagu, LinierList *LaguPlaylist){

    //----------------------------------------------------------------Opening file------------------------------
    char *filepath;
    filepath = (char *) malloc (50 * sizeof(char));
    stringConcat("../save/",filename,filepath);
    FILE *outputfile = fopen(filepath,"w");

    // if (filepath == NULL) {
    //     printf("Error opening file for writing.\n");
    //     return;
    // }
    char *fileinputpath;
    fileinputpath = (char *) malloc (50 * sizeof(char));
    stringConcat("../save/", "config.txt",fileinputpath);
    FILE *inputFile = fopen(fileinputpath, "r");
    
    
   
    //--------------------------------------------------------Menuliskan konfig ulang------------------------------------------
    char currentChar;
    while (fscanf(inputFile, "%c", &currentChar) != EOF) {
        printf("%c", currentChar); // untuk debug
        // nulis output
        fprintf(outputfile, "%c", currentChar);
    }
    fprintf(outputfile,"\n");
   
  //---------------------------------------------------------Menuliskan Current song -------------------------------------------------------
//if (!isQueueEmpty(*UrutanLagu)){
    
//     char currsong[50];
//     int k = 0;

//     while (k < 50 && UrutanLagu->buffer[UrutanLagu->idxHead].TabWord[k] != '\0')
//     {
//     currsong[k] = UrutanLagu->buffer[UrutanLagu->idxHead].TabWord[k];
//     k++;
//     }
//     currsong[k] = '\0';
//     char currPen[50];
//     char currAlb[50];

//     carialbumpenyanyi(*penyanyiAlbums, *albumsong, currsong, currPen, currAlb);
//     fprintf(outputfile, "%s;", currPen);
//     fprintf(outputfile, "%s:", currAlb);
//     fprintf(outputfile, "%s\n", currsong);
// }


 
  //---------------------------------------------------------Menuliskan Queue -------------------------------------------------------
// if (!isQueueEmpty(*UrutanLagu))
//{
    fprintf(outputfile,"%d",lengthQueue(*UrutanLagu));
//     for (int i = UrutanLagu->idxHead ; i < UrutanLagu->idxTail;i++){
//         char currsong[50];
//         int k = 0;

//         while (k < 50 && UrutanLagu->buffer[i].TabWord[k] != '\0')
//         {
//         currsong[k] = UrutanLagu->buffer[i].TabWord[k];
//         k++;
//         }
//         currsong[k] = '\0';
//         char currPen[50];
//         char currAlb[50];

//         carialbumpenyanyi(*penyanyiAlbums, *albumsong, currsong, currPen, currAlb);
//         fprintf(outputfile, "%s;", currPen);
//         fprintf(outputfile, "%s\n", currAlb);
//         fprintf(outputfile, "%s;", currsong);
//         }
//     }
// //---------------------------------------------------------Menuliskan Riwayat Lagu -------------------------------------------------------
    //  if (!IsEmptyStack(*RiwayatLagu))
    // {
            fprintf(outputfile,"%d",NbElmtStack(*RiwayatLagu));
    //     for (int i = 0; i <= RiwayatLagu->TOP; i++)
    //     {
    //         char currsong[50];
    //         int k = 0;

    //         while (k < 50 && UrutanLagu->buffer[i].TabWord[k] != '\0')
    //         {
    //         currsong[k] = UrutanLagu->buffer[i].TabWord[k];
    //         k++;
    //         }
    //         currsong[k] = '\0';
    //         char currPen[50];
    //         char currAlb[50];

    //         carialbumpenyanyi(*penyanyiAlbums, *albumsong, currsong, currPen, currAlb);
    //         fprintf(outputfile, "%s;", currPen);
    //         fprintf(outputfile, "%s\n", currAlb);
    //         fprintf(outputfile, "%s;", currsong);
    //     }
    // }
  
// //---------------------------------------------------------Menuliskan Playlist Lagu -------------------------------------------------------

//     if(!IsListEmptyDynamic(*Playlist)){
//         int playlistCount = LengthListDynamic(*Playlist);
//         fprintf(outputfile, "%d # Jumlah playlist\n", playlistCount);

//         for (int i = 0; i < playlistCount; i++)
//         {
//             fprintf(outputfile, "%d %s \n", LengthListDynamic(Playlist[i]), Playlist[i]);

//             for (int j = 1; j <= LengthListDynamic(Playlist[i]); j++)
//             {
//                 char currsong[50];
//                 int k = 0;

//                 while (k < 50 && UrutanLagu->buffer[i].TabWord[k] != '\0')
//                {
//                 currsong[k] = UrutanLagu->buffer[i].TabWord[k];
//                 k++;
//                }
//                 currsong[k] = '\0';
//                 char currPen[50];
//                 char currAlb[50];
    
//                 carialbumpenyanyi(*penyanyiAlbums, *albumsong, currsong, currPen, currAlb);
//                 fprintf(outputfile, "%s;", currPen);
//                 fprintf(outputfile, "%s\n", currAlb);
//                 fprintf(outputfile, "%s;", currsong);
//             }
//         }
//     }
    //if (filepath != NULL) {
    //     printf("Save berhasil dilakukan, Yeay!\n");
    // }
}
void CreateQueue(Queue *q){
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}
int main() {
    // Create and initialize your data structures
    StaticList penyanyi;  // Modify accordingly
    Map penyanyiAlbums;   // Modify accordingly
    maps albumsong;       // Modify accordingly
    Queue UrutanLagu;   
    DynamicList Playlist;
    CreateQueue(&UrutanLagu);
   // Modify accordingly
      // Modify accordingly
    Stack RiwayatLagu;     // Modify accordingly
    LinierList LaguPlaylist; // Modify accordingly

    // Call the save function with sample data
    save("outpu2t.txt", &penyanyi, &penyanyiAlbums, &albumsong, &UrutanLagu, &Playlist, &RiwayatLagu, &LaguPlaylist);

    return 0;
}
  
  
