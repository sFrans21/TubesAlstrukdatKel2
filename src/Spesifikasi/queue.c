
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "../tambahan.h"
#include "start.h"

void queuesong(StaticList penyanyi, Map singeralbum, maps albumsong, Queue *queue){
    int idxp;
    int idxa;
    printf("Daftar Penyanyi : \n");
    for(int i=0; i<penyanyi.itemCount; i++){
         printf("   %d. %s\n", i+1, (penyanyi).items[i].TabWord);
     }
    printf("Masukkan Nama Penyanyi : ");
    StartWordInput();
    Word artist =currentWord;
    for(int i=0; i<penyanyi.itemCount;i++)
     {if (isEqual(currentWord,(penyanyi).items[i]))
         {idxp=i;}
     }
    printf("Daftar Album oleh %s : \n", (penyanyi).items[idxp].TabWord);
    for (int i=0;i<singeralbum.Elements[idxp].Value.Count;i++){
         printf("   %d. %s\n", i+1,(singeralbum.Elements[idxp].Value.Elements[i].TabWord));}

    printf("Masukkan Nama Album : ");
    StartWordInput();
    Word album = currentWord;
    
    for (int i=0;i<albumsong.Elements[idxp].Count;i++){
        if (isEqual(currentWord, albumsong.Elements[idxp].Elements[i].Key)){
            idxa = i;
         }
     }
    printf("Daftar Lagu Album %s oleh %s : \n", albumsong.Elements[idxp].Elements[idxa].Key.TabWord, penyanyi.items[idxp].TabWord );
    for(int i=0;i<albumsong.Elements[idxp].Elements[idxa].Value.Count;i++){
        printf("    %d. %s \n", i+1, albumsong.Elements[idxp].Elements[idxa].Value.Elements[i].TabWord);
    }
    printf("Masukkan ID lagu yang dipilih : ");
    StartWordInput();
    int idxl = WordToInt(currentWord)-1;
    Word detailed = ConcatWord(artist,stringToWord(";"));
    detailed = ConcatWord(detailed,album);
    detailed = ConcatWord(detailed,stringToWord(";"));
    detailed = ConcatWord(detailed,albumsong.Elements[idxp].Elements[idxa].Value.Elements[idxl]);
    enqueue(queue, detailed);
    printf("Berhasil menambahkan lagu \"%s\" oleh \"%s\" ke queue.\n",albumsong.Elements[idxp].Elements[idxa].Value.Elements[idxl].TabWord,  (penyanyi).items[idxp].TabWord);
}   

void queueswap(Queue *queue, int idx1, int idx2){
    Word temp;
    temp = queue->buffer[idx1];
    queue->buffer[idx1]=queue->buffer[idx2];
    queue->buffer[idx2]=temp;
}

void queueremove(Queue *queue, int i)
{
	int j;
	for (j = i ; j < queue->idxTail ; j++)
	{
		queue->buffer[j] = queue->buffer[j+1]; 
	}
	
	queue->idxTail--;
}

void  queueclear(Queue *queue){
    CreateQueue(queue);
}

void queueplaylist(MapPlaylist PL, Queue *queue)
{
    if (PL.PlCount>0)
    {
    printf("Daftar Playlist :\n");
    for (int i=0;i< PL.PlCount;i++)
    {
    printf("    %d. %s\n",PL.PlElmt[i].PlaylistName.TabWord);
    }
    printf("\nMasukkan ID Playlist yang dipilih : ");
    StartWordInput();
    int idx = atoi(currentWord.TabWord)-1;
    if (idx<PL.PlCount)
    {
    addressLinier p = First(PL.PlElmt[idx].SongName);
    for(int i=0;i<NbElmt(PL.PlElmt[idx].SongName);i++){
        enqueue(queue, Info(p));
        p=Next(p);
    }
    printf("Berhasil menambahkan Plylist \"%s\" ke queue\n",PL.PlElmt[idx].PlaylistName.TabWord);
    }
    else
    {
        printf("Tidak ada Playlist dengan ID %d\n", idx+1);
    }
    }

    else
    {
        printf("Kamu tidak punya Playlist. Silahkan buat terlebih dahulu\n");
    }
    

}