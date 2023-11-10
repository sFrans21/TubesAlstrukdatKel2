#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include "ADT/mesinkarakter.h"
#include "ADT/queue.h"
#include "ADT/mesinkata.h"
#include "ADT/boolean.h"

boolean isEqual(Word a, Word b);

int WordToInt(Word word);

char *WORDTOSTRING(Word kata);

void wordToString(Word currentWord, char *string);

void stringConcat(char str1[] , char str2[] , char *output);

#endif