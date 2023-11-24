#ifndef coba_H
#define coba_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clearScreen();

// void delay(unsigned int mseconds);

void animateASCII();

void displayLoadingBar(int progress);

void animateSpinner(int duration);

void animateSpinnerStart(int duration);

#endif