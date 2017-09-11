#ifndef REGISTER_H
#define REGISTER_H

#include "instruction.h"

#define NREGS 16

short int registerFile[16];
registerFile[0] = 0;

short int getRegIndex (char *regWord);
short int getRegValue (short int index);
void setRegValue (short int index, short int value);

#endif
