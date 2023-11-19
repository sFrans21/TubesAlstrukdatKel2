#ifndef LIST_H
#define QUIT_H

#include "ADT/listStatik.h"
#include "ADT/map.h"
#include "ADT/set.h"

// // Definisi struktur Word dan Map

// #define Nil 0
// #define MaxElMap 50
// #define Undefined NULL
// #define MAX_ITEMS 100
// #define MaxElSet 100

// typedef struct
// {
//       char TabWord[50];
//       int Length;
// } Word;

// typedef Word infotypeSet;
// typedef int addrSer;

// typedef struct
// {
//       infotypeSet Elements[MaxElSet];
//       addrSer Count;
// } Set;

// typedef struct
// {
//       Word items[MAX_ITEMS];
//       int itemCount;
// } StaticList;

// typedef struct
// {
//       Word Key;
//       StaticList Value;
// } infotype1;

// typedef struct
// {
//       Word Key;
//       Set Value;
// } infotype2;

// typedef struct
// {
//       infotype2 Elements[MaxElMap];
//       int Count;
// } Map;

// Fungsi-fungsi dan prosedur-prosedur ADT Map
// ... (Implementasikan fungsi-fungsi ADT Map di sini)

// Fungsi untuk membaca file konfigurasi dan mengisi ADT Map
// void BacaKonfigurasi(Map *M, char *namaFile)
// {
//       FILE *file = fopen(namaFile, "r");

//       if (file == NULL)
//       {
//             perror("Error membuka file");
//             exit(EXIT_FAILURE);
//       }

//       int jumlahPenyanyi;
//       fscanf(file, "%d", &jumlahPenyanyi);

//       for (int i = 0; i < jumlahPenyanyi; i++)
//       {
//             Word namaPenyanyi;
//             fscanf(file, "%d %s", &namaPenyanyi.Length, namaPenyanyi.TabWord);

//             int jumlahAlbum;
//             fscanf(file, "%d", &jumlahAlbum);

//             for (int j = 0; j < jumlahAlbum; j++)
//             {
//                   Word judulAlbum;
//                   fscanf(file, "%d %s", &judulAlbum.Length, judulAlbum.TabWord);

//                   int jumlahLagu;
//                   fscanf(file, "%d", &jumlahLagu);

//                   for (int k = 0; k < jumlahLagu; k++)
//                   {
//                         Word judulLagu;
//                         fscanf(file, "%s", judulLagu.TabWord);

//                         // // Tambahkan ke dalam ADT Map
//                         // InsMap(M, namaPenyanyi, judulLagu);
//                   }
//             }
//       }

//       fclose(file);
// }

void PrintPenyanyi(StaticList *M);

// void PrintAlbum(Map M, char c) // ini gunain map penyanyi-album
// {
//     // ngecek kata c ada di key map/tidak
//     int found;
//     for (int d = 0; d < M.Count; d++)
//     {
//         for (int i = 0; i < c.Length; i++)
//         {
//             if (c != M.Elements[d].Key.TabWord[i])
//             {
//                 break;
//             }
//             found = d;
//         }
//     }
//     printf("Daftar Album oleh %s :\n", M.Elements[found].Key.TabWord);
//     for (int e = 0; e < M.Elements[found].Value.Count; e++)
//     {
//         printf("%d. ", (e + 1));
//         for (int i = 0; i < M.Elements[found].Value.Elements->Length; i++)
//         {
//             printf("%s\n", M.Elements[found].Value.Elements->TabWord[i]);
//         }
//     }
// }

// void PrintLagu(Map M, Word c) // ini gunain map album-lagu
// {
//     int found;
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

// void PrintPlaylist();

// // int main()
// // {
// // 	// inisisalisasi M
// // 	// if (input == LIST DEFAULT;)
// // 	PrintPenyanyi(M);
// // 	printf("Ingin melihat album yang ada?(Y/N): ");
// // 	// scanf("%s", %jawaban);
// // 	printf("Pilih penyanyi untuk melihat album mereka:");
// // 	// scanf("%s", %jawaban);
// // 	PrintAlbum(M, jawab);
// // 	printf("\nIngin melihat lagu yang ada pada album tersebut? (Y/N): ");
// // 	// scanf("%s", %jawaban);
// // 	PrintLagu(M, jawab);
// // }

#endif