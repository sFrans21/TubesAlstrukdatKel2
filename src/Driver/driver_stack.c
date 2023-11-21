#include <stdio.h>
#include "ADT/stack.h"

int main() {
    Stack S;
    INFOTYPE X;

    // Membuat Stack kosong
    CreateEmptyStack(&S);

    // Menambahkan elemen ke dalam Stack
    Push(&S, "Element1");
    Push(&S, "Element2");
    Push(&S, "Element3");

    // Menampilkan isi Stack
    printf("Stack elements:\n");
    while (!IsEmptyStack(S)) {
        Pop(&S, &X);
        printf("%s\n", X);
    }

    // Menampilkan panjang Stack
    printf("Stack length: %d\n", NbElmtStack(S));

    // Membuat Stack baru dari Stack yang sudah terpop
    Stack reversedStack = ReverseStack(S);

    // Menampilkan isi Stack yang sudah di-reverse
    printf("Reversed Stack elements:\n");
    while (!IsEmptyStack(reversedStack)) {
        Pop(&reversedStack, &X);
        printf("%s\n", X);
    }

    return 0;
}
