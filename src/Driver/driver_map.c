#include <stdio.h>
#include "../ADT/map.h"

int main() {
    Map map1, map2;
    Set set1, set2;

    // Membuat Map dan Set kosong
    CreateEmptymap(&map1);
    CreateEmptymap(&map2);
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

    // Menambahkan set1 ke dalam map1 dengan key "Fruits"
    Insertmap(&map1, stringToWord("Fruits"), set1);

    // Menambahkan set2 ke dalam map2 dengan key "Fruits"
    Insertmap(&map2, stringToWord("Fruits"), set2);

    // Menampilkan set yang ada pada map1 dengan key "Fruits"
    printf("Set in Map1 with key 'Fruits': ");
    PrintSet(Valuemap(map1, stringToWord("Fruits")));
    printf("\n");

    // Menampilkan set yang ada pada map2 dengan key "Fruits"
    printf("Set in Map2 with key 'Fruits': ");
    PrintSet(Valuemap(map2, stringToWord("Fruits")));
    printf("\n");

    // Menghapus set pada map1 dengan key "Fruits"
    Deletemap(&map1, stringToWord("Fruits"));

    // Menampilkan set yang ada pada map1 setelah dihapus
    printf("Set in Map1 after deletion: ");
    PrintSet(Valuemap(map1, stringToWord("Fruits")));
    printf("\n");

    // Menampilkan apakah key "Fruits" adalah member dari map1
    if (IsMembermap(map1, stringToWord("Fruits"))) {
        printf("Key 'Fruits' is a member of Map1\n");
    } else {
        printf("Key 'Fruits' is not a member of Map1\n");
    }

    return 0;
}
