#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"

// Definisi struktur Word dan Map
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
      int Count;
} Map;

// Fungsi-fungsi dan prosedur-prosedur ADT Map
// ... (Implementasikan fungsi-fungsi ADT Map di sini)

// Fungsi untuk membaca file konfigurasi dan mengisi ADT Map
void BacaKonfigurasi(Map *M, char *namaFile)
{
      FILE *file = fopen(namaFile, "r");

      if (file == NULL)
      {
            perror("Error membuka file");
            exit(EXIT_FAILURE);
      }

      int jumlahPenyanyi;
      fscanf(file, "%d", &jumlahPenyanyi);

      for (int i = 0; i < jumlahPenyanyi; i++)
      {
            Word namaPenyanyi;
            fscanf(file, "%d %s", &namaPenyanyi.Length, namaPenyanyi.TabWord);

            int jumlahAlbum;
            fscanf(file, "%d", &jumlahAlbum);

            for (int j = 0; j < jumlahAlbum; j++)
            {
                  Word judulAlbum;
                  fscanf(file, "%d %s", &judulAlbum.Length, judulAlbum.TabWord);

                  int jumlahLagu;
                  fscanf(file, "%d", &jumlahLagu);

                  for (int k = 0; k < jumlahLagu; k++)
                  {
                        Word judulLagu;
                        fscanf(file, "%s", judulLagu.TabWord);

                        // // Tambahkan ke dalam ADT Map
                        Insertmap(M, namaPenyanyi, judulLagu);
                  }
            }
      }

      fclose(file);
}

// Fungsi untuk menampilkan isi Map (hanya untuk keperluan debugging)
void PrintMap(Map M)
{
      for (int i = 0; i < M.Count; i++)
      {
            printf("Key: %s, Value: %s\n", M.Elements[i].Key.TabWord, M.Elements[i].Value.TabWord);
      }
}

int main()
{
      Map dataMap;
      // Inisialisasi dataMap jika diperlukan
      dataMap.Count = 0;

      // Panggil fungsi BacaKonfigurasi
      BacaKonfigurasi(&dataMap, "config.txt");

      // Tampilkan isi Map (hanya untuk keperluan debugging)
      PrintMap(dataMap);

      return 0;
}

void Insertmap(Map *M, Word key, Word value)
{
      if (M->Count < 100) // Pastikan array tidak penuh
      {
            strcpy(M->Elements[M->Count].Key.TabWord, key.TabWord);
            M->Elements[M->Count].Key.Length = key.Length;

            strcpy(M->Elements[M->Count].Value.TabWord, value.TabWord);
            M->Elements[M->Count].Value.Length = value.Length;

            M->Count++;
      }
      else
      {
            printf("Map penuh, tidak dapat menambahkan elemen baru.\n");
      }
}
