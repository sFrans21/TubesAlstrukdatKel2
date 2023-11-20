#include <stdio.h>
#include "list.h"

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

void PrintPenyanyi(StaticList M)
{

    printf("Daftar Penyanyi :\n");
    for (int i = 0; i < M.itemCount; i++)
    {
        printf("%d. ", (i + 1));
        printf("%s\n", M.items[i].TabWord);
    }
}

void PrintAlbum(Map M, char *C) // ini gunain map penyanyi-album
{

    // ngecek kata c ada di key map/tidak
    int when;
    boolean found;
    char asem;
    for (int d = 0; d < M.Count; d++)
    {
        wordToString(M.Elements[d].Key, &asem); // ubah ke char
        if (strcmp(C, &asem) == 0)
        {
            found = true;
            when = d;
        }
    }
    if (found == true)
    {
        printf("Daftar Album oleh %d :\n", *C);
        for (int e = 0; e < M.Elements[when].Value.Count; e++)
        {
            printf("%d. ", (e + 1));
            printf("%s\n", M.Elements[when].Value.Elements[e].TabWord);
        }
    }
}

void PrintLagu(Map M, Word c) // ini gunain map album-lagu
{
    int found = 0;
    for (int d = 0; d < M.Count; d++)
    {
        for (int i = 0; i < c.Length; i++)
        {
            if (c.TabWord[i] != M.Elements[d].Key.TabWord[i])
            {
                break;
                found = d;
            }
        }
    }
    printf("Daftar Lagu di album %s :\n", M.Elements[found].Key.TabWord);
    for (int i = 0; i < M.Elements[found].Value.Count; i++)
    {
        printf("%d. %s\n", (i + 1), M.Elements[found].Value.Elements[i].TabWord);
    }
}

void PrintPlaylist(DynamicList M)
{
    printf("Daftar Playlist yang kamu miliki:\n");
    for (int i = 0; i < M.Neff; i++)
    {
        printf("%d. %s", (i + 1), M.A[i].TabWord);
    }
}

// int main()
// {
// 	// inisisalisasi M
// 	// if (input == LIST DEFAULT;)
// 	PrintPenyanyi(M);
// 	printf("Ingin melihat album yang ada?(Y/N): ");
// 	// scanf("%s", %jawaban);
// 	printf("Pilih penyanyi untuk melihat album mereka:");
// 	// scanf("%s", %jawaban);
// 	PrintAlbum(M, jawab);
// 	printf("\nIngin melihat lagu yang ada pada album tersebut? (Y/N): ");
// 	// scanf("%s", %jawaban);
// 	PrintLagu(M, jawab);
// }

// }

// void PrintPenyanyi(StaticList M)
// {

//     printf("Daftar Penyanyi :\n");
//     for (int i = 0; i < (*M).itemCount; i++)
//     {
//         printf("%d. ", (i + 1));
//         displayList(M);
//     }
// }

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
