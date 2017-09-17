#ifndef IMMEDIATE_H
#define IMMEDIATE_H

#include "instruction.h"

short int getImmOp (InstructionType instr);
void setImmOp (InstructionType *instr, char *immStr);

#endif
