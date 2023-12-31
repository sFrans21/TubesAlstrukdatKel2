#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "mesinkarakter.h"

#define NMax 50
#define BLANK ' '
#define NEWLINE '\n'
#define STRIP '-'
#define STOP '\0'

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Kata */
extern boolean EndWord;
extern Word currentWord;
extern Word currentCommand;
extern Word hasil;

void IgnoreBlank();

void IgnoreNewline();

void StartWordInput();

// void StartWordMark();

// void StartWordBlank();

Word ConcatWord(Word word_1, Word word_2);

void StartWordFile(char *filename, int type);

void StartCommand();

void CopyCommand();

void ResetCommand();

void ADVWord();

void ADVInput();

boolean IsCommandEqual(Word Input, char * kata);

void copyString(char dest[], const char src[], int max_length);

int stringLen(char *string);

Word stringToWord(char* str);

void ADVLine();

void CopyWord();

Word CopyWordFile();

void CopyWordinput();

void ADVSemicolon();

void DisplayWord (Word Word);

boolean CekWord(Word hasil);

Word ConcatWord(Word word_1, Word word_2);

Word SplitWordBlank(Word word);

Word SplitWordMark(Word word);

Word SplitWordLeftBlank(Word word);

Word SplitWordLeftMark(Word word);

#endif