#include <stdio.h>
#include "ADT/listStatik.h"
#include "ADT/mesinkata.h"

int main() {
    StaticList staticList;

    // Inisialisasi list statis
    initializeList(&staticList);

    // Menambahkan elemen ke list statis
    Word word1 = stringToWord("Item1");
    Word word2 = stringToWord("Item2");
    Word word3 = stringToWord("Item3");

    setItem(&staticList, 0, &word1);
    setItem(&staticList, 1, &word2);
    setItem(&staticList, 2, &word3);

    // Menampilkan isi list statis
    printf("Isi Static List:\n");
    displayList(&staticList);

    return 0;
}
