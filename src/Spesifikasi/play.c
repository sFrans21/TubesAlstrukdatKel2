#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "play.h"
#include "queue.h"

// // Definisi struktur Word dan Map

// Fungsi-fungsi dan prosedur-prosedur ADT Map
// ... (Implementasikan fungsi-fungsi ADT Map di sini)

// Fungsi untuk membaca file konfigurasi dan mengisi ADT Map
// void BacaKonfigurasi(Map *M, char *namaFile)
// {

// #include <stdio.h>
// #include "list.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include "string.h"
// #include "boolean.h"
// #include "tambahan.h"

void PrintPenyanyii(StaticList M)
{

      printf("Daftar Penyanyi :\n");
      for (int i = 0; i < M.itemCount; i++)
      {
            printf("%d. ", (i + 1));
            printf("%s\n", M.items[i].TabWord);
      }
}

void PrintAlbumm(StaticList N, Map M, Word C) // ini gunain map penyanyi-album
{
      // ngecek di indeks berapa penyanyi tsb di daftar penyanyi
      boolean uy = true;
      int idx = 0;
      char *F;
      int when;
      F = (char *)malloc(30 * sizeof(char));
      wordToString(C, F);

      for (int i = 0; i < N.itemCount; i++)
      {
            if (F != N.items[i].TabWord)
            {
                  uy = false;
                  idx++;
            }
      }
      if (uy == true)
      {
            idx -= 1;
      }

      // ngecek kata c ada di key map/tidak

      char *D;
      D = (char *)malloc(30 * sizeof(char));

      char *E;
      E = (char *)malloc(30 * sizeof(char));

      for (int d = 0; d < M.Count; d++)
      {
            wordToString(C, D); // ubah ke char
            wordToString(M.Elements[d].Key, E);
            if (compareString(D, E) == true)
            {

                  when = d;
            }
      }
      for (int e = 0; e < M.Elements[when].Value.Count; e++)
      {
            printf("%d. ", (e + 1));
            printf("%s\n", M.Elements[when].Value.Elements[e].TabWord);
      }
}

void PrintLaguu(maps M, Word C, int i) // ini gunain maps album-lagu
{
      // ngecek kata c ada di key map/tidak

      int when;

      char *D;
      D = (char *)malloc(30 * sizeof(char));

      char *E;
      E = (char *)malloc(30 * sizeof(char));

      for (int d = 0; d < M.Elements->Count; d++)
      {
            wordToString(C, D); // ubah ke char
            wordToString(M.Elements[i].Elements[d].Key, E);
            if (compareString(D, E) == true)
            {

                  when = d;
            }
      }
      for (int e = 0; e < M.Elements[i].Elements[when].Value.Count; e++)
      {
            printf("%d. ", (e + 1));
            printf("%s\n", M.Elements[i].Elements[when].Value.Elements[e].TabWord);
      }
}

// {
//     int found = 0;
//     for (int d = 0; d < M.Count; d++)
//     {
//         for (int i = 0; i < c.Length; i++)
//         {
//             if (c.TabWord[i] != M.Elements[d].Key.TabWord[i])
//             {
//                 break;
//                 found = d;
//             }
//         }
//     }
//     printf("Daftar Lagu di album %s :\n", M.Elements[found].Key.TabWord);
//     for (int i = 0; i < M.Elements[found].Value.Count; i++)
//     {
//         printf("%d. %s\n", (i + 1), M.Elements[found].Value.Elements[i].TabWord);
//     }
// }

void PrintPlaylistt(DynamicList M)
{
      if (IsListEmptyDynamic(M) == false)
      {
            printf("Daftar Playlist yang kamu miliki:\n");
            for (int i = 0; i < M.Neff; i++)
            {
                  printf("%d. ", (i + 1));
                  printf("%s\n", M.A[i].TabWord);
            }
      }
      else
      {
            printf("Daftar Playlist yang kamu miliki:\n");
            printf("Kamu tidak memiliki playlist.");
      }
}
