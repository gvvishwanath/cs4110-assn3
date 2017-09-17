#include "opcodes.h"

OpcodeType getOpcode (InstructionType instr) {
	int shift = ISIZE + OP1SIZE + OP2SIZE + OP3SIZE;
	OpcodeType opcode = (OpcodeType) (instr >> shift);
	return opcode;
}

void setOpcode (InstructionType *instr, char *instrWord) {
	InstructionType newInstr;
	int shift = ISIZE + OP1SIZE + OP2SIZE + OP3SIZE;
	OpcodeType opcode = INVALID;
	
	if (strcmp(instrWord, "ADD\0") == 0) {
		opcode = ADD;
	}
	else if (strcmp(instrWord, "SUB\0") == 0) {
		opcode = SUB;
	}
	else if (strcmp(instrWord, "MUL\0") == 0) {
		opcode = MUL;
	}
	else if (strcmp(instrWord, "LD\0") == 0) {
		opcode = LD;
	}
	else if (strcmp(instrWord, "SD\0") == 0) {
		opcode = SD;
	}
	else if (strcmp(instrWord, "JMP\0") == 0) {
		opcode = JMP;
	}
	else if (strcmp(instrWord, "BEQZ\0") == 0) {
		opcode = BEQZ;
	}
	else if (strcmp(instrWord, "HLT\0") == 0) {
		opcode = HLT;
	}
	else {
		printf("Fatal error: Invalid instruction encountered: %s\n", instrWord);
		exit(0);
	}
	
	newInstr = opcode << shift;
	newInstr += ((*instr) << CSIZE) >> CSIZE;
	*instr = newInstr;
}  
