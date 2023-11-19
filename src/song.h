#ifndef SONG_H
#define SONG_H

// Struktur data untuk representasi lagu
typedef struct {
    char singer[50];
    char album[50];
    char songtitle[50];
} Song;

// Node untuk representasi elemen dalam queue
typedef struct Node {
    Song data;
    struct Node* next;
} Node;

// Struktur data untuk representasi queue lagu
typedef struct {
    Node* head;
    Node* tail;
} SongQueue;

// Fungsi untuk membuat node baru dalam queue
Node* createNode(Song song);

// Fungsi untuk membuat queue lagu baru
SongQueue* createQueue();

// Fungsi untuk menambahkan lagu ke dalam queue
void enqueuesong(SongQueue* queue, Song song);

// Fungsi untuk memutar lagu selanjutnya dalam queue
void playNextSong(SongQueue* queue);

// Fungsi untuk memutar lagu sebelumnya dalam queue
void playPreviousSong(SongQueue* queue, Song currentSong);

#endif // SONG_H
