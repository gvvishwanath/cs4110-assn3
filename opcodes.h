#ifndef OPCODES_H
#define OPCODES_H

#include "instruction.h"

enum opcodes {
	ADD, SUB, MUL, LD, SD, JMP, BEQZ, HLT
}
typedef enum opcodes OpcodeType;

OpcodeType getOpcode (InstructionType instr);
void setOpcode (InstructionType instruction, char *instrWord);

#endif
