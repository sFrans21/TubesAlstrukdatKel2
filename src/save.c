#include "save.h"
#include <stdio.h>
#include <stdlib.h>
#include "tambahan.h"
#include "struc.h"
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
void savefile(char *filename, QueueLagu  *UrutanLagu, ListPlaylist *Playlist, HistoriLagu *RiwayatLagu){
    //----------------------------------------------------------------Opening file------------------------------
    char filepath[100];
    stringConcat("../save/", filename,filepath);
    FILE *outputfile = fopen(filepath,"w");
    
    printf("\n");

    if (filepath == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    char fileinputpath[100];
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
    //----------------------------------------------------Queue Lagu--------------------------------

    fprintf(outputfile, "%s;%s;%s\n", UrutanLagu->Isi[UrutanLagu->idxHead].lagu_playlist, UrutanLagu->Isi[UrutanLagu->idxHead].album_playlist, UrutanLagu->Isi[UrutanLagu->idxHead].Penyanyi_playlist);

  
    fprintf(outputfile, "%d\n", UrutanLagu->idxTail - UrutanLagu->idxHead);

    // Tulis record-record lagu dalam queue
    for (int i = UrutanLagu->idxHead; i < UrutanLagu->idxTail; i++) {
        fprintf(outputfile, "%s;%s;%s\n", UrutanLagu->Isi[i].lagu_playlist, UrutanLagu->Isi[i].album_playlist, UrutanLagu->Isi[i].Penyanyi_playlist);
    }


    //---------------------------------------------------- Stack Riwayat lagu-----------------------------

    fprintf(outputfile, "%d\n", RiwayatLagu->count + 1);

  
    for (int i = 0; i < RiwayatLagu->count; i++) {
        fprintf(outputfile, "%s;%s;%s\n", RiwayatLagu->hist_lagu[i].lagu_playlist, RiwayatLagu->hist_lagu[i].album_playlist, RiwayatLagu->hist_lagu[i].Penyanyi_playlist);
    }
 
    //------------------------------------------------ Playlist Lagu-----------------------------------------
    fprintf(outputfile, "%d\n", Playlist->playlistSize);

    // Tulis record-record playlist
    for (size_t i = 0; i < Playlist->playlistSize; i++) {
        fprintf(outputfile, "%d %s\n", Playlist->playlist[i].isi, Playlist->playlist[i].playlist_nama);
        
        // Tulis lagu-lagu di dalam playlist
        for (int j = 0; j < Playlist->playlist[i].isi; j++) {
            fprintf(outputfile, "%s;%s;%s\n", Playlist->playlist[i].playlist_user[j].lagu_playlist, 
                    Playlist->playlist[i].playlist_user[j].album_playlist, 
                    Playlist->playlist[i].playlist_user[j].Penyanyi_playlist);
        }
    }

    fclose(outputfile);
    fclose(inputFile);
}

int main() {
    // Inisialisasi QueueLagu
    QueueLagu UrutanLagu;
    UrutanLagu.idxHead = 0;
    UrutanLagu.idxTail = 0;

    // Tambahkan beberapa lagu ke dalam queue
    Isi_Que lagu1 = {"Lagu1", "Album1", "Penyanyi1"};
    Isi_Que lagu2 = {"Lagu2", "Album2", "Penyanyi2"};

    // Inisialisasi ListPlaylist
    ListPlaylist Playlist;
    Playlist.playlist = malloc(MaxEl * sizeof(NamaPlaylist));
    Playlist.playlistSize = 0;

    // Tambahkan beberapa lagu ke dalam playlist
    NamaPlaylist playlist1;
    playlist1.isi = 2;
    

    Playlist.playlist[Playlist.playlistSize++] = playlist1;

    // Inisialisasi HistoriLagu
    HistoriLagu RiwayatLagu;
    RiwayatLagu.idxTop = -1;
    RiwayatLagu.count = 0;

    // Tambahkan beberapa lagu ke dalam histori
    Isi_Que histori1 = {"Histori1", "Album1", "Penyanyi1"};
    Isi_Que histori2 = {"Histori2", "Album2", "Penyanyi2"};

    pushHistory(&RiwayatLagu, histori1);
    pushHistory(&RiwayatLagu, histori2);

    // Memanggil fungsi savefile untuk menyimpan data ke dalam file
    savefile("output.txt", &UrutanLagu, &Playlist, &RiwayatLagu);

    // Dealokasi memori
    free(Playlist.playlist);

    return 0;
}
