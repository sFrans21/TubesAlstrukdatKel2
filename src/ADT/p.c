#include <stdio.h>
#include "ListStatik.h"
int main()
{
      StaticList M = {{{"Word1"}, {"Word2"}, {"Word3"}, {"Word3"}, {"Word3"}, {"Word3"}}, 6};

      printf("Daftar Penyanyi :\n");
      for (int i = 0; i < M.itemCount; i++)
      {
            printf("%d. ", (i + 1));
            printf("%s\n", M.items[i].TabWord);
      }
}
