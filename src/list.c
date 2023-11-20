#include <stdio.h>
#include <stdlib.h>
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
    char *D;
    D = (char *)malloc(30 * sizeof(char));
    boolean found;
    int when;
    // Word asem;
    // char asem[20];
    for (int d = 0; d < M.Count; d++)
    {
        // asem = M.Elements[d].Key;
        wordToString(M.Elements[d].Key, D); // ubah ke char
        if (compareString(upper(D), C) == true)
        {
            found = true;
            when = d;
        }
    }
    if (found == true)
    {
        printf("Daftar Album oleh %s :\n", C);
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
        // printf("%d %s", ())
    }
}
