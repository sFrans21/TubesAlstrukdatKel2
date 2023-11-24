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
    stringConcat("../save/",inputfile,filepath); // Membuat file path untuk file tujuan
    FILE *outputfile = fopen(filepath,"w");
  
    //--------------------------------------------------------Menuliskan konfig ulang------------------------------------------
   
   fprintf(outputfile, "%d\n", penyanyi->itemCount);

for (int i = 0; i < penyanyi->itemCount; i++) {
    fprintf(outputfile, "%d %s\n", penyanyiAlbums->Elements[i].Value.Count, penyanyi->items[i].TabWord); // Menuliskan jumlah dan nama penyanyi


    for (int j = 0; j < penyanyiAlbums->Elements[i].Value.Count; j++) {
        fprintf(outputfile, "%d %s\n", albumsong->Elements[i].Elements[j].Value.Count, albumsong->Elements[i].Elements[j].Key.TabWord); // Album


        for (int k = 0; k < albumsong->Elements[i].Elements[j].Value.Count; k++) {
            fprintf(outputfile, "%s\n", albumsong->Elements[i].Elements[j].Value.Elements[k].TabWord); // Lagu
        }
    }
}
  //---------------------------------------------------------Menuliskan Current song -------------------------------------------------------

//if (!(IsCommandEqual(*currentSong,"-")|| IsCommandEqual(*currentSong,"")))
   // {
     
         int icur = 0;
         while (icur < currentSong->Length)
        {
            fprintf(outputfile,"%c", currentSong->TabWord[icur]);
            icur++;
        }
        fprintf(outputfile,"\n");
//}



 
  //---------------------------------------------------------Menuliskan Queue -------------------------------------------------------
  

    fprintf(outputfile,"%d\n",lengthQueue(*UrutanLagu));
        for (int i = UrutanLagu->idxHead  ; i <= UrutanLagu->idxTail;i++){
        fprintf(outputfile,"%s\n", UrutanLagu->buffer[i].TabWord);
            }



    
//---------------------------------------------------------Menuliskan Riwayat Lagu -------------------------------------------------------
//      if (!IsEmptyStack(*RiwayatLagu))
//     {
        fprintf(outputfile,"%d\n",NbElmtStack(*RiwayatLagu));
         for (int i = RiwayatLagu->TOP; i >= 0; i--)
         {
            fprintf(outputfile,"%s\n", RiwayatLagu->T[i].TabWord);
     }
     
//---------------------------------------------------------Menuliskan Playlist Lagu -------------------------------------------------------

//      if(!IsListEmptyDynamic(*Playlist)){
        int playlistCount = LengthListDynamic(*Playlist);
        fprintf(outputfile, "%d # Jumlah playlist\n", playlistCount);

        // for (int i = 0; i < playlistCount; i++)
        // {
        //     fprintf(outputfile, "%d %s \n", Playlist->A->Length, Playlist[i]);

        //     for (int j = 1; j <= LengthListDynamic(Playlist[i]); j++)
        //     {
                
        //     }
        // }
//     }
//     if (filepath != NULL) {
        printf("Save berhasil dilakukan, Yeay!\n");
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
  
  
