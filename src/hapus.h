#ifndef hapus_H
#define hapus_H
#include "boolean.h"
#include "mesinkata.h"
#include "string.h"
// Definisi struktur Word dan Map
typedef int address;

typedef struct
{
      char TabWord[50];
      int Length;
} Word;

typedef struct
{
      Word Key;
      Word Value;
} infotype;

typedef struct
{
      infotype Elements[100]; // Sesuaikan ukuran array sesuai kebutuhan
      address Count;
} Map;

// Fungsi-fungsi dan prosedur-prosedur ADT Map
// ... (Implementasikan fungsi-fungsi ADT Map di sini)

// Fungsi untuk membaca file konfigurasi dan mengisi ADT Map
void BacaKonfigurasi(Map *M, char *namaFile);


// Fungsi untuk menampilkan isi Map (hanya untuk keperluan debugging)
void PrintMap(Map M);




void InsMap(Map *M, Word key, Word value);

#endif