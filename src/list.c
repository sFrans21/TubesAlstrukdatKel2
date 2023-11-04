#include <stdio.h>
#include "list.h"

void list()
{
    FILE *file = fopen("config.txt", "r");
    if (file == NULL)
    {
        printf("Gagal membuka file konfigurasi.\n");
        return;
    }
    else
    {
        int BarisBerbaris;
        fscanf(file, "%d", &BarisBerbaris);
    }
}