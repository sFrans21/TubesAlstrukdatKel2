#include <stdio.h>
#include <stdlib.h>
#include "save.h"
#include "status.h"
#include "../tambahan.h"




// void carialbumpenyanyi(Map singeralbum, maps albumsong, char *songname, char *curP, char *curA) {
//     // Pencarian lagu dalam struktur data albumsong
//     int found = 0;  // Flag untuk menandakan apakah lagu ditemukan
//     int idxp, idxa, idxl;

//     for (idxp = 0; idxp < singeralbum.Count; idxp++) {
//         for (idxa = 0; idxa < singeralbum.Elements[idxp].Value.Count; idxa++) {
//             for (idxl = 0; idxl < albumsong.Elements[idxp].Elements[idxa].Value.Count; idxl++) {
//                 // Menggunakan strcmp untuk membandingkan string
//                 if (songname == albumsong.Elements[idxp].Elements[idxa].Value.Elements[idxl].TabWord) {
//                     found = 1;
//                     break;
//                 }
//             }
//             if (found) {
//                 break;
//             }
//         }
//         if (found) {
//             break;
//         }
//     }

//     // Menyalin hasil pencarian ke variabel curP dan curA
//     if (found) {
//         curP = singeralbum.Elements[idxp].Key.TabWord;
//         curA = singeralbum.Elements[idxp].Value.Elements[idxa].TabWord;
//     }
// }


void save(char *inputfile, StaticList *penyanyi, Map *penyanyiAlbums, maps *albumsong, Queue *UrutanLagu, DynamicList *Playlist, Stack *RiwayatLagu, LinierList *LaguPlaylist, Word *currentSong){

    //----------------------------------------------------------------Opening file------------------------------
    char filepath[50];
    // filepath = (char *) malloc (50 * sizeof(char));
    stringConcat("../save/",inputfile,filepath);
    FILE *outputfile = fopen(filepath,"w");
   
    // if (filepath == NULL) {
    //     printf("Error opening file for writing.\n");
    //     return;
    // }
    // char *fileinputpath;
    // fileinputpath = (char *) malloc (50 * sizeof(char));
    // stringConcat("../save/", "config.txt",fileinputpath);
    // FILE *inputFile = fopen(fileinputpath, "r");
    
    
   
    //--------------------------------------------------------Menuliskan konfig ulang------------------------------------------
    // char currentChar;
    // while (fscanf(inputFile, "%c", &currentChar) != EOF) {
    //     //printf("%c", currentChar); // untuk debug
    //     // nulis output
    //     fprintf(outputfile, "%c", currentChar);
    // }
    // fprintf(outputfile,"\n");
   fprintf(outputfile, "%d\n", penyanyi->itemCount);

for (int i = 0; i < penyanyi->itemCount; i++) {
    fprintf(outputfile, "%d %s\n", penyanyiAlbums->Elements[i].Value.Count, penyanyi->items[i].TabWord);

    // Perbaikan: Gunakan indeks i untuk mengakses data dari penyanyiAlbums
    for (int j = 0; j < penyanyiAlbums->Elements[i].Value.Count; j++) {
        fprintf(outputfile, "%d %s\n", albumsong->Elements[i].Elements[j].Value.Count, albumsong->Elements[i].Elements[j].Key.TabWord);

        // Perbaikan: Gunakan indeks i dan j untuk mengakses data dari penyanyiAlbums
        for (int k = 0; k < albumsong->Elements[i].Elements[j].Value.Count; k++) {
            fprintf(outputfile, "%s\n", albumsong->Elements[i].Elements[j].Value.Elements[k].TabWord);
        }
    }
}
  //---------------------------------------------------------Menuliskan Current song -------------------------------------------------------
// if (!isQueueEmpty(*UrutanLagu)){
    
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
if ((IsCommandEqual(*currentSong,"-")|| IsCommandEqual(*currentSong,"")))
    {
        printf("");
        
    }
else{
     char* carcurr[50];
         wordToString(*currentSong,*carcurr);
         int i = 0;
         while (i < currentSong->Length){
            fprintf(outputfile,"%c",carcurr[i]);
         }
         fprintf(outputfile,"\n");
}



 
  //---------------------------------------------------------Menuliskan Queue -------------------------------------------------------
  

    fprintf(outputfile,"%d\n",lengthQueue(*UrutanLagu));
            for (int i = UrutanLagu->idxHead  ; i < UrutanLagu->idxTail;i++){
            // char currsong[50];
            // int k = 0;

            // while (k < 50 && UrutanLagu->buffer[i].TabWord[k] != '\0')
            // {
            //     currsong[k] = UrutanLagu->buffer[i].TabWord[k];
            //     k++;
            // }
            // currsong[k] = '\0';
            // char currPen[50];
            // char currAlb[50];
            // carialbumpenyanyi(*penyanyiAlbums, *albumsong, currsong, currPen, currAlb);
            fprintf(outputfile,"%s\n", UrutanLagu->buffer[i]);
            }

// if (!isQueueEmpty(*UrutanLagu))
// {
//     fprintf(outputfile,"%d\n",lengthQueue(*UrutanLagu));
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


    
// // //---------------------------------------------------------Menuliskan Riwayat Lagu -------------------------------------------------------
//      if (!IsEmptyStack(*RiwayatLagu))
//     {
//             fprintf(outputfile,"%d\n",NbElmtStack(*RiwayatLagu));
//         for (int i = 0; i <= RiwayatLagu->TOP; i++)
//         {
//             char currsong[50];
//             int k = 0;

//             while (k < 50 && UrutanLagu->buffer[i].TabWord[k] != '\0')
//             {
//             currsong[k] = UrutanLagu->buffer[i].TabWord[k];
//             k++;
//             }
//             currsong[k] = '\0';
//             char currPen[50];
//             char currAlb[50];

//             carialbumpenyanyi(*penyanyiAlbums, *albumsong, currsong, currPen, currAlb);
//             fprintf(outputfile, "%s;", currPen);
//             fprintf(outputfile, "%s\n", currAlb);
//             fprintf(outputfile, "%s;", currsong);
//         }
//     }
     
// // //---------------------------------------------------------Menuliskan Playlist Lagu -------------------------------------------------------

//      if(!IsListEmptyDynamic(*Playlist)){
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
//     if (filepath != NULL) {
//         printf("Save berhasil dilakukan, Yeay!\n");
//     }

   
}

// int main() {
//     // Create and initialize your data structures
//     StaticList penyanyi;  // Modify accordingly
//     Map penyanyiAlbums;   // Modify accordingly
//     maps albumsong;       // Modify accordingly
//     Queue UrutanLagu;   
//     DynamicList Playlist;
//     CreateQueue(&UrutanLagu);
//    // Modify accordingly
//       // Modify accordingly
//     Stack RiwayatLagu;     // Modify accordingly
//     LinierList LaguPlaylist; // Modify accordingly

//     // Call the save function with sample data
//     save("outpu2t.txt", &penyanyi, &penyanyiAlbums, &albumsong, &UrutanLagu, &Playlist, &RiwayatLagu, &LaguPlaylist);

//     return 0;
// }
  
  
