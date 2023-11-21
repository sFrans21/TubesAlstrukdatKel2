#include <stdio.h>
#include "../ADT/list_linier.h"

int main() {
    LinierList list;
    addressLinier P;

    // Inisialisasi list linier
    CreateEmptyLinier(&list);

    // Menambahkan elemen ke list
    InsVFirst(&list, stringToWord("Element1"));
    InsVLast(&list, stringToWord("Element2"));
    InsVLast(&list, stringToWord("Element3"));

    // Menampilkan isi list
    printf("Isi List Linier:\n");
    PrintInfo(list);
    printf("\n");

    // Mencari elemen pada list
    // Contoh: mencari elemen dengan nilai "Element2"
    P = Search(list, stringToWord("Element2"));
    if (P != NilLinier) {
        printf("Elemen 'Element2' ditemukan pada list.\n");
    } else {
        printf("Elemen 'Element2' tidak ditemukan pada list.\n");
    }

    // Menghapus elemen pertama dan terakhir
    DelFirst(&list, &P);
    DelLast(&list, &P);

    // Menampilkan isi list setelah penghapusan
    printf("\nIsi List Linier setelah penghapusan:\n");
    PrintInfo(list);
    printf("\n");

    // Menghapus elemen setelah elemen pertama
    DelAfter(&list, &P, First(list));

    // Menampilkan isi list setelah penghapusan
    printf("\nIsi List Linier setelah penghapusan:\n");
    PrintInfo(list);
    printf("\n");

    // Dealokasi list
    Dealokasi(&P);

    return 0;
}
