#include <stdio.h>
#include <stdlib.h>
#include "save.h"
#include "status.h"
#include "../tambahan.h"


void carialbumpenyanyi(Map singeralbum, maps albumsong, char *songname, char *curP, char *curA)
{
    // Pencarian lagu dalam struktur data albumsong
    int found = 0; // Flag untuk menandakan apakah lagu ditemukan
    int idxp, idxa, idxl;

    for (idxp = 0; idxp < singeralbum.Count; idxp++)
    {
        for (idxa = 0; idxa < singeralbum.Elements[idxp].Value.Count; idxa++)
        {
            for (idxl = 0; idxl < albumsong.Elements[idxp].Elements[idxa].Value.Count; idxl++)
            {
                // Menggunakan strcmp untuk membandingkan string
                if (songname != albumsong.Elements[idxp].Elements[idxa].Value.Elements[idxl].TabWord)
                {
                    found = 1;
                    break;
                }
            }
            if (found)
            {
                break;
            }
        }
        if (found)
        {
            break;
        }
    }
}
int countAlbumsBySinger(Map singeralbum, maps albumsong, char *singerName) {
    int idxp, idxa;
    int albumCount = 0;  // Jumlah album yang akan dihitung

    for (idxp = 0; idxp < singeralbum.Count; idxp++) {
        // Membandingkan string secara karakter per karakter
        int i;
        for (i = 0; singerName[i] != '\0' && singeralbum.Elements[idxp].Key.TabWord[i] != '\0'; i++) {
            if (singerName[i] != singeralbum.Elements[idxp].Key.TabWord[i]) {
                break;  // Jika karakter tidak cocok, keluar dari loop
            }
        }

        // Jika loop di atas selesai dan kedua string masih cocok, maka penyanyi ditemukan
        if (singerName[i] == '\0' && singeralbum.Elements[idxp].Key.TabWord[i] == '\0') {
            // Penyanyi ditemukan, hitung jumlah albumnya
            for (idxa = 0; idxa < singeralbum.Elements[idxp].Value.Count; idxa++) {
                albumCount++;
            }
            break;  // Keluar dari loop jika penyanyi ditemukan
        }
    }

    return albumCount;
}



void save(char *inputfile, StaticList *penyanyi, Map *penyanyiAlbums, maps *albumsong, Queue *UrutanLagu, DynamicList *Playlist, Stack *RiwayatLagu, LinierList *LaguPlaylist){

    //----------------------------------------------------------------Opening file------------------------------
    char *filepath;
    filepath = (char *) malloc (50 * sizeof(char));
    stringConcat("../../save/",inputfile,filepath);
    FILE *outputfile = fopen(filepath,"w");

  
    char *fileinputpath;
    fileinputpath = (char *) malloc (50 * sizeof(char));
    stringConcat("../save/", "config.txt",fileinputpath);
    FILE *inputFile = fopen(fileinputpath, "r");
    
    
   
    //--------------------------------------------------------Menuliskan konfig ulang------------------------------------------
    // char currentChar;
    // while (fscanf(inputFile, "%c", &currentChar) != EOF) {
    //     //printf("%c", currentChar); // untuk debug
    //     // nulis output
    //     fprintf(outputfile, "%c", currentChar);
    // }
    // fprintf(outputfile,"\n");
     fprintf(outputfile, "%d # Jumlah penyanyi\n", penyanyi->itemCount);

        for (int i = 0; i < penyanyi->itemCount; i++) {
            fprintf(outputfile, "%d %s # Jumlah album dan nama dari penyanyi %d\n", penyanyiAlbums->Elements[i].Value.Count, penyanyi->items[i].TabWord, i + 1);

           

            for (int j = 0; j < penyanyiAlbums->Count; j++) {
                fprintf(outputfile, "%d %s # Jumlah lagu dan judul dari album  penyanyi \n", albumsong->Elements[i].Elements[j].Value.Count, penyanyiAlbums[i].Elements[j].Key.TabWord);

                for (int k = 0; k < albumsong->Elements[j].Elements[k].Value.Count; k++) {
                    fprintf(outputfile, "%s # Lagu  album  penyanyi\n", albumsong->Elements[i].Elements[j].Value.Elements[k].TabWord);
                }

                
            }
        }
  //---------------------------------------------------------Menuliskan Current song -------------------------------------------------------
if (!isQueueEmpty(*UrutanLagu)){
    
    char currsong[50];
    int k = 0;

    while (k < 50 && UrutanLagu->buffer[UrutanLagu->idxHead].TabWord[k] != '\0')
    {
    currsong[k] = UrutanLagu->buffer[UrutanLagu->idxHead].TabWord[k];
    k++;
    }
    currsong[k] = '\0';
    char currPen[50];
    char currAlb[50];

    carialbumpenyanyi(*penyanyiAlbums, *albumsong, currsong, currPen, currAlb);
    fprintf(outputfile, "%s;", currPen);
    fprintf(outputfile, "%s:", currAlb);
    fprintf(outputfile, "%s\n", currsong);
}


// if(!isQueueEmptyBELV(*UrutanLagu)){
//   fprintf(outputfile,"%s;",UrutanLagu->QueueDetail[UrutanLagu->idxHeadBELV].SingerName);
//   fprintf(outputfile,"%s;",UrutanLagu->QueueDetail[UrutanLagu->idxHeadBELV].AlbumName);
//   fprintf(outputfile,"%s\n",UrutanLagu->QueueDetail[UrutanLagu->idxHeadBELV].SongTitle);
//   fprintf(outputfile,"%s;",CS->SingerName);
//   fprintf(outputfile,"%s;",CS->AlbumName);
//   fprintf(outputfile,"%s\n",CS->SongTitle);
// }
 
  //---------------------------------------------------------Menuliskan Queue -------------------------------------------------------
if (!isQueueEmpty(*UrutanLagu))
{
    fprintf(outputfile,"%d\n",lengthQueue(*UrutanLagu));
    for (int i = UrutanLagu->idxHead ; i < UrutanLagu->idxTail;i++){
        char currsong[50];
        int k = 0;

        while (k < 50 && UrutanLagu->buffer[i].TabWord[k] != '\0')
        {
        currsong[k] = UrutanLagu->buffer[i].TabWord[k];
        k++;
        }
        currsong[k] = '\0';
        char currPen[50];
        char currAlb[50];

        carialbumpenyanyi(*penyanyiAlbums, *albumsong, currsong, currPen, currAlb);
        fprintf(outputfile, "%s;", currPen);
        fprintf(outputfile, "%s\n", currAlb);
        fprintf(outputfile, "%s;", currsong);
        }
    }

// if (!isQueueEmptyBELV(*UrutanLagu))
// {
//     fprintf(outputfile,"%d\n",lengthQueueBELV(*UrutanLagu));
//     for (int i = (UrutanLagu->idxHeadBELV) + 1 ; i < UrutanLagu->idxTailBELV;i++){

//         fprintf(outputfile, "%s;", UrutanLagu->QueueDetail[i].SingerName);
//         fprintf(outputfile, "%s;", UrutanLagu->QueueDetail[i].AlbumName);
//         fprintf(outputfile, "%s\n", UrutanLagu->QueueDetail[i].SongTitle);
//         }
//     }
// //---------------------------------------------------------Menuliskan Riwayat Lagu -------------------------------------------------------
     if (!IsEmptyStack(*RiwayatLagu))
    {
            fprintf(outputfile,"%d\n",NbElmtStack(*RiwayatLagu));
        for (int i = 0; i <= RiwayatLagu->TOP; i++)
        {
            char currsong[50];
            int k = 0;

            while (k < 50 && UrutanLagu->buffer[i].TabWord[k] != '\0')
            {
            currsong[k] = UrutanLagu->buffer[i].TabWord[k];
            k++;
            }
            currsong[k] = '\0';
            char currPen[50];
            char currAlb[50];

            carialbumpenyanyi(*penyanyiAlbums, *albumsong, currsong, currPen, currAlb);
            fprintf(outputfile, "%s;", currPen);
            fprintf(outputfile, "%s\n", currAlb);
            fprintf(outputfile, "%s;", currsong);
        }
    }
//      if (!IsEmptyRiwayat(*History))
//     {
//         fprintf(outputfile,"%d\n",History->TopRiwayat + 1);
//         for (int i = History->TopRiwayat; i >= 0; i--)
//         {
//             fprintf(outputfile, "%s;", History->detil_history[i].namaPenyanyi);
//             fprintf(outputfile, "%s;", History->detil_history[i].namaAlbum);
//             fprintf(outputfile, "%s\n", History->detil_history[i].namaLagu);
//         }
//     }
// // //---------------------------------------------------------Menuliskan Playlist Lagu -------------------------------------------------------

     if(!IsListEmptyDynamic(*Playlist)){
        int playlistCount = LengthListDynamic(*Playlist);
        fprintf(outputfile, "%d # Jumlah playlist\n", playlistCount);

        for (int i = 0; i < playlistCount; i++)
        {
            fprintf(outputfile, "%d %s \n", LengthListDynamic(Playlist[i]), Playlist[i]);

            for (int j = 1; j <= LengthListDynamic(Playlist[i]); j++)
            {
                char currsong[50];
                int k = 0;

                while (k < 50 && UrutanLagu->buffer[i].TabWord[k] != '\0')
               {
                currsong[k] = UrutanLagu->buffer[i].TabWord[k];
                k++;
               }
                currsong[k] = '\0';
                char currPen[50];
                char currAlb[50];
    
                carialbumpenyanyi(*penyanyiAlbums, *albumsong, currsong, currPen, currAlb);
                fprintf(outputfile, "%s;", currPen);
                fprintf(outputfile, "%s\n", currAlb);
                fprintf(outputfile, "%s;", currsong);
            }
        }
    }
    if (filepath != NULL) {
        printf("Save berhasil dilakukan, Yeay!\n");
    }

    //  if(Playlist->Neff != 0){
    //     int playlistCount = Playlist->Neff;
    //     fprintf(outputfile, "%d # Jumlah playlist\n", playlistCount);

    //     for (int iPlay = 0; iPlay < Playlist->Neff; iPlay++ ){
    //       fprintf(outputfile,"%s;",Playlist->IsiPlaylist->judulLagu.First->info.Penyanyi.TabWord);
    //       fprintf(outputfile,"%s;",Playlist->IsiPlaylist->judulLagu.First->info.Album.TabWord);
    //       fprintf(outputfile,"%s\n",Playlist->IsiPlaylist->judulLagu.First->info.Lagu.TabWord);
    //     }
    //  }

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
  
  
