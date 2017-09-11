#ifndef MEMORY_H
#define MEMORY_H

#include "instruction.h"

#define CODE_START 0
#define CODE_END 511
#define DATA_START 512
#define DATA_END 1023
#define MEM_SIZE 1024

char memory[MEM_SIZE];

void loadBinary (InstructionType *binary, short int length);

void loadValue (short int location, short int nBytes);
void storeValue (short int location, short int nBytes, short int value);

short int getLabel (InstructionType instr);
void setLabel (InstructionType instr, char *label, char *asmCode);

#endif
