#include "immediate.h"
#include <stdio.h>
#include <stdib.h>

short int getImmOp (InstructionType instr) {
	int shift1 = CSIZE + ISIZE + OP1SIZE + OP2SIZE;
	int shift2 = OP1SIZE + OP2SIZE + OP3SIZE;
	short int immOp;

	if ((instr>>shift2) %2 == 1) {
		immOp = (instr << shift1) >> shift1;
		return immOp;
	}
	printf("Fatal error: In instruction %d, operand at immediate position is not an immediate\n", instr);
	exit(0);
}

void setImmOp (InstructionType *instr, char *immStr) {
	int shift1 = CSIZE + ISIZE + OP1SIZE + OP2SIZE;
	int shift2 = OP1SIZE + OP2SIZE + OP3SIZE;
	InstructionType newInstr;
	
	short int immOp = (short int) atoi(immStr+1);	
	newInstr = instr >> shift2;
	newInstr += 1;
	newInstr = newInstr << shift1;
	newInstr += immOp;
	*instr = newInstr;
}
