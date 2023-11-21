
#include <stdio.h>
#include "queue.h"
#include "tambahan.h"
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
    // printf("%d\n", penyanyi.itemCount);
    // printf("%s\n", (penyanyi).items[1].TabWord);
    // printf("%d\n", currentWord.Length);
    // for (int i = 0; i < currentWord.Length; i++)
    // {
    //     printf("%c", currentWord.TabWord[i]);
    // }
    // printf("%d\n", penyanyi.items[0].Length);
    for(int i=0; i<penyanyi.itemCount;i++)
     {if (isEqual(currentWord,(penyanyi).items[i]))
         {idxp=i;}
     }
    printf("Daftar Album oleh %s : \n", (penyanyi).items[idxp].TabWord);
    for (int i=0;i<singeralbum.Elements[idxp].Value.Count;i++){
         printf("   %d. %s\n", i+1,(singeralbum.Elements[idxp].Value.Elements[i].TabWord));}

    printf("Masukkan Nama Album : ");
    StartWordInput();
    // printf("%d\n", albumsong.Elements[idxp].Elements[0].Key.Length);
    // for (int i = 0; i < albumsong.Elements[idxp].Elements[0].Key.Length; i++)
    // {
    //     printf("%d : %c\n", i, albumsong.Elements[idxp].Elements[0].Key.TabWord[i]);
    // }
    
    // printf("%s\n", albumsong.Elements[idxp].Elements[0].Key.TabWord);
    
    // printf("%d\n", currentWord.Length);
    // for (int i = 0; i < currentWord.Length; i++)
    // {
    //     printf("%c", currentWord.TabWord[i]);
    // }
    // printf("\n");
    // printf(".");
    // printf("%d", albumsong.Elements[idxp].Elements[2].Key.Length);
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
    enqueue(queue, albumsong.Elements[idxp].Elements[idxa].Value.Elements[idxl]);
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

// int main (){
//     StaticList penyanyi;
//     Map penyanyiAlbums;
//     maps albumLagu;
//     Queue queue;
//     CreateQueue(&queue);
//     initializeList(&penyanyi);
//     CreateEmptymap(&penyanyiAlbums);
//     createmaps(&albumLagu);
//     start(&penyanyi, &penyanyiAlbums, &albumLagu);
//     queuesong(penyanyi, penyanyiAlbums, albumLagu, &queue);
//     queuesong(penyanyi, penyanyiAlbums, albumLagu, &queue);   
//     displayQueue(queue);
//     queueswap(&queue, 0, 1);
//     displayQueue(queue);
//     queueremove(&queue, 0);
//     displayQueue(queue);
//     queueclear(&queue);
//     displayQueue(queue);
// }