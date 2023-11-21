#include <stdio.h>
#include <stdlib.h>
#include "../song.h"
#include "../queue.h"

// Fungsi untuk memutar lagu berikutnya dalam antrian
void playnextsong(Queue *queue) {
    if (!isEmptyQueue(*queue)) {
        Word currentSong = dequeue(queue);
        printf("Now playing the next song: %s\n", currentSong.TabWord);
    } else {
        printf("Queue is empty. Cannot play the next song.\n");
    }
}

// Fungsi untuk memutar lagu sebelumnya dalam antrian
void playprevioussong(Queue *queue) {
    if (!isEmptyQueue(*queue)) {
        printf("Now playing the previous song...\n");
        // Implementasi untuk memainkan lagu sebelumnya dapat ditambahkan di sini
        // Misalnya, dengan mengakses elemen di indeks tertentu dan memainkannya
    } else {
        printf("Queue is empty. Cannot play the previous song.\n");
    }
}
