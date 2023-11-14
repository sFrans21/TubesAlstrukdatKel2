#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "song.h"

void enqueue(SongQueue* queue, Song song)
{
    Node* newNode = createNode(song);
    if (queue->tail == NULL) {
        // Queue kosong
        queue->head = queue->tail = newNode;
    } else {
        // Tambahkan di urutan ke-2 atau setelah HEAD
        newNode->next = queue->head->next;
        queue->head->next = newNode;
        if (newNode->next == NULL) {
            // Jika newNode adalah elemen terakhir, update tail
            queue->tail = newNode;
        }
    }
}

// Fungsi untuk memutar lagu sebelumnya dalam queue
void playPreviousSong(SongQueue* queue, Song currentSong)
{
    Node* newNode = createNode(currentSong);

    // Masukkan lagu yang sedang diputar ke dalam queue di urutan pertama
    newNode->next = queue->head;
    queue->head = newNode;

    // Jika queue kosong sebelum lagu diputar, update tail menjadi newNode
    if (queue->tail == NULL) {
        queue->tail = newNode;
    }

    // Simulasikan pemutaran lagu
    printf("Now Playing: %s - %s (ID: %d)\n", currentSong.singer, currentSong.album, currentSong.songId);
}

// Fungsi untuk memutar lagu selanjutnya dalam queue
void playNextSong(SongQueue* queue)
{
    if (queue->head != NULL) {
        // Ambil lagu yang akan diputar
        Song currentSong = queue->head->data;

        // Pindahkan HEAD ke elemen selanjutnya
        Node* temp = queue->head;
        queue->head = queue->head->next;

        // Jika queue kosong setelah lagu diputar, update tail menjadi NULL
        if (queue->head == NULL) {
            queue->tail = NULL;
        }

        // Simulasikan pemutaran lagu
        printf("Now Playing: %s - %s (ID: %d)\n", currentSong.singer, currentSong.album, currentSong.songId);
    } else {
        printf("Queue is empty.\n");
    }
}
