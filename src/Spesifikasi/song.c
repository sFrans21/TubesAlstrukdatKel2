#include <stdio.h>
#include <stdlib.h>
#include "song.h"
#include "queue.h"
#include "../boolean.h"


void NotPlaying(){
    (&current)->penyanyi = NULL;
    (&current)->album = NULL;
    (&current)->lagu = NULL;
}

void NotPlayingPlaylist(){
    current.playlistID = -1;
}

boolean isNotPlayingPlaylist(){
    return current.playlistID == -1;
}

boolean isNotPlaying (){
    return current.penyanyi == NULL && 
    current.album == NULL && 
    current.lagu == NULL;
}

void SongNext(Stack *RiwayatLagu, Queue *queue){
    if(isNotPlaying() && CIsEmpty(*queue)){
        printf("Queue kosong dan tidak ada lagu yang sedang dimainkan\n");
    }else if(CIsEmpty(*queue)) {
        printf("Queue kosong, memutar kembali lagu\n");
        printf("\"%s\" oleh \"%s\"",current.lagu,current.penyanyi);
    }else{
        PushLagu(RiwayatLagu,current.lagu,current.album,current.penyanyi);
        Cdequeue(queue,&current.lagu,&current.album,&current.penyanyi);
        printf("Memutar lagu selanjutnya\n");
        printf("\"%s\" oleh \"%s\"\n",current.penyanyi,current.lagu);
    }
}

/*I.S. Antrian pada lagu sudah terdefinisi  */
/*F.S. Jika keadaan belum memutar lagu tetapi sudah ada que maka akan memuta lagu pada que, Jika sedang memutar lagu 
maka lagu akan dimasukkan pada History Lagu dan memutar lagu pada queue*/
void SongPrev(Stack *RiwayatLagu,Queue *queue){
    Queue Qtemp;
    char *lagutemp,*albumtemp,*penyanyitemp;
    CCreateQueue(&Qtemp);
     if (isNotPlaying() && IsHistEmpty (*RiwayatLagu)){
        printf("\nRiwayat lagu kosong dan tidak ada lagu yang sedang dimainkan\n");
    }else if(IsHistEmpty(*RiwayatLagu)){
        printf("History kosong, memutar kembali lagu\n");
        printf("\"%s\" oleh \"%s\"\n",current.penyanyi,current.lagu);
    }else{
        Cenqueue(&Qtemp,current.penyanyi,current.album,current.lagu);
        while(!CIsEmpty(*queue)){
            Cdequeue(queue,&penyanyitemp,&albumtemp,&lagutemp);
            Cenqueue(&Qtemp,penyanyitemp,albumtemp,lagutemp);
        }while(CIsEmpty(Qtemp)){
            Cdequeue(&Qtemp,&penyanyitemp,&albumtemp,&lagutemp);
            Cenqueue(queue,penyanyitemp,albumtemp,lagutemp);
        }PopLagu(RiwayatLagu,(current).lagu,(current).album,(current).penyanyi);
        printf("Memutar lagu sebelumnya\n");
        printf("\"%s\" oleh \"%s\"\n", current.penyanyi, current.lagu);
    }
}
/*I.S. History  pada lagu sudah terdefinisi  */
/*F.S Memutar lagu pada history lagu, jika belum ada dan baru memutar laguu yang diputar maka lagu 
lagu yang sedang diputar*/
