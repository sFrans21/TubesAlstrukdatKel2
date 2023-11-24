#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include <stdio.h>

#include "color.h"

#define MAX_LEN 5000

void delay(int seconds);

void pics(FILE *filename);

void welcome();

void starting();

void loading();

void quitting();

#endif