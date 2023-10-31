#ifndef MESINKALIMAT_H
#define MESINKALIMAT_H

#include "boolean.h"

#define MARK '\n'

extern char CC;
extern boolean EndKata;
extern boolean EndFile;

void START(char *filename);
void ADV();
char GetCC();

#endif
