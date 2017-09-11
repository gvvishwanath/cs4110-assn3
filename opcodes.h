#ifndef OPCODES_H
#define OPCODES_H

#include "instruction.h"

typedef short int OpcodeType;

#define ADD 0
#define SUB 1
#define MUL 2
#define LD 3
#define SD 4
#define JMP 5
#define BEQZ 6
#define HLT 7

OpcodeType getOpcode (InstructionType instr);
void setOpcode (InstructionType instruction, char *instrWord);

#endif
