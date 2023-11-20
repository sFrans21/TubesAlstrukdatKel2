#include "save.h"

void savefile(char *filename, Queue *UrutanLagu, ArrayDin *Playlist, Stack *RiwayatLagu){
    //----------------------------------------------------------------Opening file------------------------------
    FILE *savean = fopen(filename,'w');
    char filepath[100];
    stringConcat("../save/", savean,filepath);
    
    printf("\n");

    if (filepath == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    FILE *inputFile = fopen("config.txt", "r");
    char fileinputpath[100];
    stringConcat("../save/", inputFile,fileinputpath);
    
   
    //--------------------------------------------------------Menuliskan konfig ulang------------------------------------------
    char currentChar;
  
    while (fscanf(fileinputpath, "%c", &currentChar) != EOF) {
        printf("%c", currentChar); // untuk debug
        // nulis output
        fprintf(filepath, "%c", currentChar);
    }
    
    //----------------------------------------------------Queue Lagu--------------------------------
    //Riwayat Lagu
    Node *current = UrutanLagu->idxHead;
    // Menulis lagu yang sedang dimainkan
    fprintf(filepath, "%s;%s;%s # Lagu yang sedang dimainkan\n",current->data.singer,current->data.album,current->data.songtitle);

    // Menulis jumlah record lagu dalam queue
    fprintf(filepath, "%d # Jumlah record lagu dalam queue\n", UrutanLagu->idxTail - UrutanLagu->idxHead);

    // Menulis lagu dalam queue
 
    current = current->next;
    while (current != NULL) {
        fprintf(filepath, "%s;%s;%s\n",current->data.singer,current->data.album,current->data.songtitle);

        current = current->next;
    }


    //---------------------------------------------------- Stack Riwayat lagu-----------------------------
    // Menulis jumlah record riwayat pemutaran lagu
     fprintf(filepath, "%d # Jumlah record riwayat pemutaran lagu\n", SizeStack(*RiwayatLagu));

    // Menyimpan riwayat pemutaran lagu
    while (!IsEmptyStack(*RiwayatLagu)) {
        INFOTYPE currentInfo = InfoTop(*RiwayatLagu);
        Song currentSong;
        sscanf(currentInfo, "%[^;];%[^;];%[^\n]", currentSong.singer, currentSong.album, currentSong.songtitle);
        fprintf(filepath, "%s;%s;%s\n", currentSong.singer, currentSong.album, currentSong.songtitle);
        Pop(RiwayatLagu, NULL);
    }

    //------------------------------------------------ Playlist Lagu-----------------------------------------
        fprintf(filepath, "%d\n", Playlist->Neff);
    // for (int i = 0; i < Playlist->Neff; i++) {
    //     INFOTYPE currentInfo = Playlist->A[i];
    //     Song currentSong;
    //     sscanf(currentInfo, "%[^;];%[^;];%[^\n]", currentSong.singer, currentSong.album, currentSong.songtitle);
    //     fprintf(filepath, "%d %s\n", 1, "NoPlaylistName");
    //     fprintf(filepath, "%s;%s;%s\n", currentSong.singer, currentSong.album, currentSong.songtitle);
    //}
    // gw bingung dimana structure yang nyimpen playlistnya 

    fclose(savean);
    fclose(inputFile);
}
