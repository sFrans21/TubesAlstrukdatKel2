#include "ADT/array.h"
#include <stdio.h>

int main() {
    TabInt T1, T2, T3;
    IdxType i;

    // Inisialisasi tabel T1
    MakeEmpty(&T1);
    for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++) {
        SetEl(&T1, i, i);
    }

    // Inisialisasi tabel T2
    MakeEmpty(&T2);
    for (i = GetFirstIdx(T2); i <= GetLastIdx(T2); i++) {
        SetEl(&T2, i, 2 * i);
    }

    // Menampilkan isi T1
    printf("Isi Tabel T1:\n");
    TulisIsi(T1);

    // Menampilkan isi T2
    printf("\nIsi Tabel T2:\n");
    TulisIsi(T2);

    // Menambahkan T1 dan T2, hasilnya disimpan dalam T3
    T3 = PlusTab(T1, T2);

    // Menampilkan hasil penjumlahan T1 dan T2 (T3)
    printf("\nIsi Tabel T1 + T2:\n");
    TulisIsi(T3);

    // Menampilkan nilai maksimum dan minimum dari T3
    printf("\nNilai Maksimum T3: %d\n", ValMax(T3));
    printf("Nilai Minimum T3: %d\n", ValMin(T3));

    // Menampilkan indeks elemen maksimum dan minimum dari T3
    printf("Indeks Maksimum T3: %d\n", IdxMaxTab(T3));
    printf("Indeks Minimum T3: %d\n", IdxMinTab(T3));

    return 0;
}
