#include "immediate.h"

short int getImmOp (InstructionType instr) {
	int shift = CSIZE + ISIZE + OP1SIZE + OP2SIZE;
	short int immOp = (instr << shift) >> shift;
	return immOp;
}

void setImmOp (InstructionType *instr, char *immStr) {
	int shift1 = CSIZE + ISIZE + OP1SIZE + OP2SIZE;
	int shift2 = ISIZE + OP1SIZE + OP2SIZE + OP3SIZE;
	InstructionType newInstr;
	
	short int immOp = (short int) atoi(immStr+1);	
	newInstr = instr >> shift2;
	newInstr += (1 << CSIZE);
	newInstr = newInstr << shift1;
	newInstr += immOp;
	*instr = newInstr;
}
