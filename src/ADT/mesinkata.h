#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "mesinkarakter.h"

#define NMax 50
#define BLANK ' '
#define NEWLINE '\n'

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Kata */
extern boolean EndWord;
extern Word currentWord;

void IgnoreBlank();

void IgnoreNewline();

void StartWordInput();

void StartWordFile(char *directory);

void ADVWord();

void ADVLine();

void CopyWord();

Word CopyWordFile();

void CopyWordinput();

#endif
