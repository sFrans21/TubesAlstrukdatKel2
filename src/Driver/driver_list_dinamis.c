#include <stdio.h>
#include "ADT/list_dinamis.h"
#include "ADT/mesinkata.h"

int main() {
    DynamicList dynamicList;
    IdxType i;

    // Inisialisasi list dinamis
    CreateEmptyDynamic(&dynamicList);

    // Menambahkan elemen ke list
    InsertLastDynamic(&dynamicList, stringToWord("Element1"));
    InsertLastDynamic(&dynamicList, stringToWord("Element2"));
    InsertLastDynamic(&dynamicList, stringToWord("Element3"));

    // Menampilkan isi list
    printf("Isi Dynamic List:\n");
    for (i = 0; i < LengthListDynamic(dynamicList); i++) {
        printf("%s\n", WordToString(GetDynamic(dynamicList, i)));
    }

    // Menambahkan elemen ke list pada posisi terakhir
    InsertLastDynamic(&dynamicList, stringToWord("Element4"));

    // Menampilkan isi list setelah penambahan
    printf("\nIsi Dynamic List setelah penambahan:\n");
    for (i = 0; i < LengthListDynamic(dynamicList); i++) {
        printf("%s\n", WordToString(GetDynamic(dynamicList, i)));
    }

    // Menampilkan banyaknya elemen efektif list
    printf("\nBanyaknya elemen efektif Dynamic List: %d\n", LengthListDynamic(dynamicList));

    // Dealokasi list
    DealokasiDynamic(&dynamicList);

    return 0;
}
