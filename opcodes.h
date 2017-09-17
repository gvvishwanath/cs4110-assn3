#ifndef OPCODES_H
#define OPCODES_H

#include "instruction.h"

enum opcodes {
	ADD, SUB, MUL, LD, SD, JMP, BEQZ, HLT, INVALID
}
typedef enum opcodes OpcodeType;

OpcodeType getOpcode (InstructionType instr);
void setOpcode (InstructionType *instr, char *instrWord);

#endif
