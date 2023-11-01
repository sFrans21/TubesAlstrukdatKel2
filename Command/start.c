#include "start.h"
#include "mesinkata.h"
#include "mesinkarakter.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_PENYANYI 100 // Batasan maksimum penyanyi
#define MAX_ALBUM 10     // Batasan maksimum album per penyanyi
#define MAX_LAGU 20      // Batasan maksimum lagu per album

typedef struct {
    char nama[100]; // Nama penyanyi
    struct Album {
        char nama[100]; // Nama album
        struct Lagu {
            char nama[100]; // Nama lagu
        } lagu[MAX_LAGU];
        int jumlahLagu; // Jumlah lagu dalam album
    } album[MAX_ALBUM];
    int jumlahAlbum; // Jumlah album penyanyi
} Penyanyi;

Penyanyi penyanyiList[MAX_PENYANYI]; // Array untuk menyimpan penyanyi

void IgnoreBlanks() {
    while (currentChar == BLANK) {
        ADV();
    }
}

void CopyString(char dest[], Word source) {
    int i;
    for (i = 0; i < source.Length; i++) {
        dest[i] = source.TabWord[i];
    }
    dest[i] = '\0';
}

void CopyWord(Word *dest, Word source) {
    dest->Length = source.Length;
    for (int i = 0; i < source.Length; i++) {
        dest->TabWord[i] = source.TabWord[i];
    }
    dest->TabWord[dest->Length] = '\0';
}


void Start(char *configFileName) {
    STARTWORD();
    // Baca jumlah penyanyi
    ADVWORD();
    int jumlahPenyanyi;
    if (isEndWord()) {
        printf("File konfigurasi aplikasi kosong.\n");
        return;
    } else {
        jumlahPenyanyi = (int)(currentWord.TabWord[0] - '0');
    }

    int penyanyiIndex = 0;
    for (int i = 0; i < jumlahPenyanyi; i++) {
        IgnoreBlanks();
        ADVWORD();
        CopyWord(&(penyanyiList[penyanyiIndex].nama), currentWord);
        penyanyiList[penyanyiIndex].jumlahAlbum = 0;

        // Baca album
        ADVWORD();
        int albumIndex = 0;
        while (!isEndWord()) {
            IgnoreBlanks();
            if (isEndWord()) {
                break;
            } else {
                int jumlahLagu = (int)(currentWord.TabWord[0] - '0');
                ADVWORD();
                for (int laguIndex = 0; laguIndex < jumlahLagu; laguIndex++) {
                    CopyWord(&(penyanyiList[penyanyiIndex].album[albumIndex].lagu[laguIndex].nama), currentWord);
                    penyanyiList[penyanyiIndex].album[albumIndex].jumlahLagu++;
                    ADVWORD();
                }
                albumIndex++;
            }
        }
        penyanyiList[penyanyiIndex].jumlahAlbum = albumIndex;
        penyanyiIndex++;
    }

    // Setelah membaca dan mengolah data, cetak pesan sukses
    printf("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n");
}
