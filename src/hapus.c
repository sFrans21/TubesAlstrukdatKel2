/*PROGRAM UTAMA*/
// int main()
// {

// }

// map2.Elements[map2.Count].Value.Length = strlen("Lagu1");
//       map2.Count++;

//       strcpy(map2.Elements[map2.Count].Key.TabWord, "Album2");
//       map2.Elements[map2.Count].Key.Length = strlen("Album2");
//       strcpy(map2.Elements[map2.Count].Value.TabWord, "Lagu2");
//
// // int main()
// // {
// //       Map dataMap;
// //       // Inisialisasi dataMap jika diperlukan
// //       dataMap.Count = 0;

// //       // Panggil fungsi BacaKonfigurasi
// //       BacaKonfigurasi(&dataMap, "config.txt");

// //       // Tampilkan isi Map (hanya untuk keperluan debugging)
// //       PrintMap(dataMap);

// //       return 0;
// // }
// int main()
// {
//       // Inisialisasi Map
//       Map map1;
//       Map map2;
//       map1.Count = 0;
//       map2.Count = 0;

//       // Menambahkan data ke Map2
//       strcpy(map2.Elements[map2.Count].Key.TabWord, "Album1");
//       map2.Elements[map2.Count].Key.Length = strlen("Album1");
//       strcpy(map2.Elements[map2.Count].Value.TabWord, "Lagu1");
//          map2.Elements[map2.Count].Value.Length = strlen("Lagu2");
//       map2.Count++;

//       strcpy(map2.Elements[map2.Count].Key.TabWord, "Album3");
//       map2.Elements[map2.Count].Key.Length = strlen("Album3");
//       strcpy(map2.Elements[map2.Count].Value.TabWord, "Lagu3");
//       map2.Elements[map2.Count].Value.Length = strlen("Lagu3");
//       map2.Count++;

//       strcpy(map2.Elements[map2.Count].Key.TabWord, "Album4");
//       map2.Elements[map2.Count].Key.Length = strlen("Album4");
//       strcpy(map2.Elements[map2.Count].Value.TabWord, "Lagu4");
//       map2.Elements[map2.Count].Value.Length = strlen("Lagu4");
//       map2.Count++;

//       // nambahin data ke map1
//       strcpy(map1.Elements[map1.Count].Key.TabWord, "Penyanyi1");
//       map1.Elements[map1.Count].Key.Length = strlen("Penyanyi1");
//       strcpy(map1.Elements[map1.Count].Value.TabWord, "Album1");
//       map1.Elements[map1.Count].Value.Length = strlen("Album1");
//       map1.Count++;

//       strcpy(map1.Elements[map1.Count].Key.TabWord, "Penyanyi2");
//       map1.Elements[map1.Count].Key.Length = strlen("Penyanyi2");
//       strcpy(map1.Elements[map1.Count].Value.TabWord, "Album2");
//       map1.Elements[map1.Count].Value.Length = strlen("Album2");
//       map1.Count++;

//       strcpy(map1.Elements[map1.Count].Key.TabWord, "Penyanyi3");
//       map1.Elements[map1.Count].Key.Length = strlen("Penyanyi3");
//       strcpy(map1.Elements[map1.Count].Value.TabWord, "Album3");
//       map1.Elements[map1.Count].Value.Length = strlen("Album3");
//       map1.Count++;

//       strcpy(map1.Elements[map1.Count].Key.TabWord, "Penyanyi4");
//       map1.Elements[map1.Count].Key.Length = strlen("Penyanyi4");
//       strcpy(map1.Elements[map1.Count].Value.TabWord, "Album4");
//       map1.Elements[map1.Count].Value.Length = strlen("Album4");
//       map1.Count++;

//       // Lanjutkan sampai 10 data...

//       // Menampilkan isi Map
//       // printf("Isi Map:\n");
//       // for (address i = 0; i < map2.Count; i++)
//       // {
//       //       printf("Album: %s, Lagu: %s\n", map2.Elements[i].Key.TabWord, map2.Elements[i].Value.TabWord);
//       // }
//       PrintPenyanyi(map1);
//       PrintAlbum(map1);
//       PrintLagu(map2);
//       return 0;
// }

// #include <stdio.h>
// #include <string.h>

// #define MaxElMap 50
// #define Nil 0
// #define Undefined NULL

// typedef int address;

// typedef struct
// {
//       char TabWord[50];
//       int Length;
// } Word;

// typedef struct
// {
//       Word Key;
//       Word Values[MaxElMap]; // Array untuk menyimpan multiple values
//       int ValuesCount;       // Jumlah values yang terkait dengan key
// } infotype;

// typedef struct
// {
//       infotype Elements[MaxElMap];
//       address Count;
// } Map;

// // Fungsi untuk menampilkan isi Map
// void displayMap(Map *M)
// {
//       for (address i = 0; i < M->Count; i++)
//       {
//             printf("Elemen ke-%d:\n", i);
//             printf("   Key: \"%s\", Length: %d\n", M->Elements[i].Key.TabWord, M->Elements[i].Key.Length);
//             for (int j = 0; j < M->Elements[i].ValuesCount; j++)
//             {
//                   printf("   Value ke %d: \"%s\", Length: %d\n", j + 1, M->Elements[i].Values[j].TabWord, M->Elements[i].Values[j].Length);
//             }
//       }
// }

// // Fungsi untuk menambahkan elemen ke dalam Map
// void insertMap(Map *M, Word key, Word value)
// {
//       if (M->Count < MaxElMap)
//       { // Pastikan array tidak penuh
//             // Cari apakah key sudah ada di map
//             address i = 0;
//             while (i < M->Count && strcmp(M->Elements[i].Key.TabWord, key.TabWord) != 0)
//             {
//                   i++;
//             }

//             // Jika key belum ada, tambahkan ke map
//             if (i == M->Count)
//             {
//                   strcpy(M->Elements[i].Key.TabWord, key.TabWord);
//                   M->Elements[i].Key.Length = key.Length;
//                   M->Elements[i].ValuesCount = 0;
//                   M->Count++;
//             }

//             // Tambahkan value ke set values yang terkait dengan key
//             strcpy(M->Elements[i].Values[M->Elements[i].ValuesCount].TabWord, value.TabWord);
//             M->Elements[i].Values[M->Elements[i].ValuesCount].Length = value.Length;
//             M->Elements[i].ValuesCount++;
//       }
// }

// int main()
// {
//       // Inisialisasi Map
//       Map map1;
//       map1.Count = 0;

//       // Contoh penambahan elemen ke dalam Map
//       Word penyanyi1 = {"Penyanyi1", 9};
//       Word album1 = {"Album1", 6};
//       insertMap(&map1, penyanyi1, album1);

//       Word penyanyi2 = {"Penyanyi2", 9};
//       Word album2 = {"Album2", 7};
//       insertMap(&map1, penyanyi2, album2);

//       Word penyanyi3 = {"Penyanyi3", 9};
//       Word album3 = {"Album3", 7};
//       insertMap(&map1, penyanyi3, album3);

//       // Menampilkan isi Map
//       displayMap(&map1);

//       return 0;
// }
