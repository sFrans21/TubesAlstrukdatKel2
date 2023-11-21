#include <stdio.h>
#include "ADT/set.h"

int main() {
    Set set1, set2, unionSet, intersectionSet, symmetricDiffSet, subtractSet;
    CreateEmptySet(&set1);
    CreateEmptySet(&set2);

    // Menambahkan elemen ke dalam set1
    InsertSet(&set1, stringToWord("Apple"));
    InsertSet(&set1, stringToWord("Banana"));
    InsertSet(&set1, stringToWord("Cherry"));

    // Menambahkan elemen ke dalam set2
    InsertSet(&set2, stringToWord("Banana"));
    InsertSet(&set2, stringToWord("Cherry"));
    InsertSet(&set2, stringToWord("Orange"));

    // Menampilkan elemen-elemen set1
    printf("Set 1: ");
    PrintSet(set1);
    printf("\n");

    // Menampilkan elemen-elemen set2
    printf("Set 2: ");
    PrintSet(set2);
    printf("\n");

    // Mencari elemen yang terdapat pada set1 atau set2
    unionSet = SetUnion(set1, set2);
    printf("Union Set: ");
    PrintSet(unionSet);
    printf("\n");

    // Mencari elemen yang terdapat pada set1 dan set2
    intersectionSet = SetIntersection(set1, set2);
    printf("Intersection Set: ");
    PrintSet(intersectionSet);
    printf("\n");

    // Mencari elemen yang terdapat pada set1 atau set2, tapi tidak keduanya
    symmetricDiffSet = SetSymmetricDifference(set1, set2);
    printf("Symmetric Difference Set: ");
    PrintSet(symmetricDiffSet);
    printf("\n");

    // Mencari elemen yang terdapat pada set1, tapi tidak pada set2
    subtractSet = SetSubtract(set1, set2);
    printf("Subtract Set: ");
    PrintSet(subtractSet);
    printf("\n");

    return 0;
}
