#ifndef MESINKATA_H
#define MESINKATA_H

#include "boolean.h"
#include <stdio.h>

#define NMax 100
#define BLANK ' '

typedef struct {
    char TabKata[NMax];
    int Length;
} Kata;

extern Kata CKata;
extern boolean EndKata;

void IgnoreBlank();
void STARTKATA();
void ADVKATA();
boolean IsKataSama(Kata K1, const char *K2);

#endif
