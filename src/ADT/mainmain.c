#include <stdio.h>
#include "map.h"

// Fungsi untuk menampilkan isi Map
void PrintMap(Map M)
{
      for (int i = 0; i < M.Count; i++)
      {
            printf("Penyanyi: %s\n", M.Elements[i].Key.TabWord);
            printf("Album:\n");
            for (int j = 0; j < M.Elements[i].Value.Count; j++)
            {
                  printf("  %s\n", M.Elements[i].Value.Elements[j].Key.TabWord);
                  for (int k = 0; k < M.Elements[i].Value.Elements[j].Value.Count; k++)
                  {
                        printf("    %s\n", M.Elements[i].Value.Elements[j].Value.Elements[k].TabWord);
                  }
            }
            printf("\n");
      }
}

// Prosedur untuk mengisi Map dengan data album dan lagu
void IsiDataMap(Map *M)
{
      Word penyanyiA, penyanyiB;
      Word albumA1, albumA2, albumB1, albumB2;
      Word lagu1, lagu2, lagu3, lagu4;

      // Inisialisasi data penyanyi, album, dan lagu
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

      strcpy(lagu1.TabWord, "Lagu 1");
      lagu1.Length = strlen(lagu1.TabWord);

      strcpy(lagu2.TabWord, "Lagu 2");
      lagu2.Length = strlen(lagu2.TabWord);

      strcpy(lagu3.TabWord, "Lagu 3");
      lagu3.Length = strlen(lagu3.TabWord);

      strcpy(lagu4.TabWord, "Lagu 4");
      lagu4.Length = strlen(lagu4.TabWord);

      // Inisialisasi Map
      CreateEmptymap(M);

      // Insert data ke Map
      Insertmap(M, penyanyiA, CreateEmptymap(albumA1));
      Insertmap(M, penyanyiA, CreateEmptymap(albumA2));
      Insertmap(M, penyanyiB, CreateEmptymap(albumB1));
      Insertmap(M, penyanyiB, CreateEmptymap(albumB2));

      // Menambahkan lagu ke dalam album
      Insertmap(&M->Elements[0].Value, albumA1, lagu1);
      Insertmap(&M->Elements[0].Value, albumA1, lagu2);
      Insertmap(&M->Elements[0].Value, albumA2, lagu3);
      Insertmap(&M->Elements[1].Value, albumB1, lagu4);
}

int main()
{
      Map dataMap;
      IsiDataMap(&dataMap);

      // Menampilkan isi Map
      PrintMap(dataMap);

      return 0;
}
// mappp