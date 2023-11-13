#include <stdio.h>
#include <string.h>

#define MaxElMap 10
#define Nil -1

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
      infotype Elements[MaxElMap];
      int Count;
} Map;

// Fungsi untuk menampilkan isi Map
void PrintMap(Map M)
{
      for (int i = 0; i < M.Count; i++)
      {
            printf("Key: %s, Value: %s\n", M.Elements[i].Key.TabWord, M.Elements[i].Value.TabWord);
      }
}

// Prosedur untuk mengisi Map dengan data album dan lagu
void IsiDataMap(Map *M)
{
      Word penyanyiA, penyanyiB;
      Word albumA1, albumA2, albumB1, albumB2;

      // Inisialisasi data penyanyi dan album
      strcpy(penyanyiA.TabWord, "Penyanyi A");
      penyanyiA.Length = strlen(penyanyiA.TabWord);

      strcpy(penyanyiB.TabWord, "Penyanyi B");
      penyanyiB.Length = strlen(penyanyiB.TabWord);

      strcpy(albumA1.TabWord, "Album A1");
      albumA1.Length = strlen(albumA1.TabWord);

      strcpy(albumA2.TabWord, "Album A2");
      albumA2.Length = strlen(albumA2.TabWord);

      strcpy(albumB1.TabWord, "Album B1");
      albumB1.Length = strlen(albumB1.TabWord);

      strcpy(albumB2.TabWord, "Album B2");
      albumB2.Length = strlen(albumB2.TabWord);

      // Inisialisasi Map
      M->Count = 0;

      // Insert data ke Map
      M->Elements[M->Count].Key = penyanyiA;
      M->Elements[M->Count].Value = albumA1;
      M->Count++;

      M->Elements[M->Count].Key = penyanyiA;
      M->Elements[M->Count].Value = albumA2;
      M->Count++;

      M->Elements[M->Count].Key = penyanyiB;
      M->Elements[M->Count].Value = albumB1;
      M->Count++;

      M->Elements[M->Count].Key = penyanyiB;
      M->Elements[M->Count].Value = albumB2;
      M->Count++;
}

int main()
{
      Map dataMap;
      IsiDataMap(&dataMap);

      // Menampilkan isi Map
      PrintMap(dataMap);

      return 0;
}
