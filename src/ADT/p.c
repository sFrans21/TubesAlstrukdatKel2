#include <stdio.h>
#include "ListStatik.h"
#include "set.h"
#include "map.h"
// int main()
// {
//       StaticList M = {{{"Word1"}, {"Word2"}, {"Word3"}, {"Word3"}, {"Word3"}, {"Word3"}}, 6};
//       Set H = {{{"fewgeg"}, {"gwvgV"}, {"GEGEGG"}, {"nivnin"}}, 4};
//       Map myMap = {
//           {{"Key1"}, {{{"fewgeg"}, {"gwvgV"}, {"GEGEGG"}, {"nivnin"}}, 4}},
//           {{"Key2"}, {{{"fewgeg"}, {"gwvgV"}, {"GEGEGG"}, {"nivnin"}}, 4}},
//           // ... (beberapa pasangan key-value lainnya)
//       };
// }
#include <stdio.h>

#define MaxElSet 100
#define MaxElMap 50
#define NMax 50
#define BLANK ' '
#define NEWLINE '\n'
#define Nil 0

typedef struct
{
      char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
      int Length;
} Word;

typedef Word keytype;
typedef Set valuetype;
typedef int address;
typedef Word infotypeSet;
typedef int addrSer;

typedef struct
{
      keytype Key;
      valuetype Value;
} infotype;

typedef struct
{
      infotype Elements[MaxElMap];
      address Count;
} Map;

typedef struct
{
      infotypeSet Elements[MaxElSet];
      addrSer Count;
} Set;

void printMap(const Map *myMap)
{
      printf("Map Contents:\n");
      for (int i = 0; i < myMap->Count; i++)
      {
            printf("Key: %s\n", myMap->Elements[i].Key.TabWord);
            // You can customize the display of Value according to your needs
            printf("Value: <custom_display>\n");
            printf("\n");
      }
}

int main()
{
      // Inisialisasi Map dengan beberapa pasangan key-value
      Map myMap = {
          {{"Key1"}, {{{"fewgeg"}, {"gwvgV"}, {"GEGEGG"}, {"nivnin"}}, 4}},
          {{"Key2"}, {{{"eagegrg"}, {"gwvrgrgV"}, {"GEGreEGG"}, {"nivrnin"}}, 4}},
          // ... (beberapa pasangan key-value lainnya)
          2 // Count
      };

      // Memanggil fungsi printMap untuk menampilkan output Map
      printMap(&myMap);

      return 0;
}
