#include "register.h"
#include <stdio.h>
#include <stdlib.h>

void initPorts (void) {
	writePort[0] = PORT_FREE;
	readPort[0] = readPort[1] = PORT_FREE;
}

void initRegFile (char *regFile) {
}

short int getRegIndex (InstructionType instr, short int opNum) {
	int shift1, shift2;
	short int regIndex;
	
	if (opNum < 0 || opNum >= 3) {
		printf("Fatal error: Invalid operand number %d\n", opNum);
		exit(0);
	}
	
	else if (opNum == 0) {
		shift1 = CSIZE + ISIZE;
		shift2 = shift1 + OP2SIZE + OP3SIZE;
		regIndex = (instr << shift1) >> shift2;
	}
	
	else if (opNum == 1) {
		shift1 = CSIZE + ISIZE + OP1SIZE;
		shift2 = shift1 + OP3SIZE;
		regIndex = (instr << shift1) >> shift2;
	}
	
	else if (opNum == 2) {
		shift1 = CSIZE + ISIZE + OP1SIZE + OP2SIZE;
		shift2 = OP1SIZE + OP2SIZE + OP3SIZE;
		
		if ((instr>>shift2) %2 == 0) {
			regIndex = (instr << shift1) >> shift1;
			return regIndex;
		}
		else {
			printf("Fatal error: In instruction %d, operand at register position is not a register\n", instr);
			exit(0);
		}
	} 
	
	return regIndex;
}

void setRegIndex (InstructionType *instr, short int opNum, char *regWord) {
	int shift1, shift2;
	short int regIndex = atoi(regWord+1);
	InstructionType newInstr;
	
	if (opNum < 0 || opNum >= 3) {
		printf("Fatal error: Invalid operand number %d\n", opNum);
		exit(0);
	}
	
	else if (opNum == 0) {
		shift1 = CSIZE + ISIZE + OP1SIZE;
		shift2 = OP2SIZE + OP3SIZE;
	}
	
	else if (opNum == 1) {
		shift1 = CSIZE + ISIZE + OP1SIZE + OP2SIZE;
		shift2 = OP3SIZE;
	}
	
	else if (opNum == 2) {
		shift1 = CSIZE+ISIZE;
		shift2 = OP1SIZE + OP2SIZE + OP3SIZE;
		
		newInstr = ((*instr) >> shift2+1)<<1;
		newInstr = (newInstr << shift2) + (((*instr) << shift1) >> shift1);
		*instr = newInstr;
		
		shift1 = CSIZE + ISIZE + OP1SIZE + OP2SIZE + OP3SIZE;
		shift2 = 0;		
	} 

	newInstr = ((*instr) >> shift2) + regIndex;
	newInstr = (newInstr << shift2) + (((*instr) << shift1) >> shift1);
	*instr = newInstr;
}

short int readRegValue (short int index) {
	if (index >= 0 && index < NREGS) {
		while (readPorts[0]== PORT_BUSY && readPorts[1] == PORT_BUSY);
		return registerFile[index];
	}
	printf("Error: Tried to access invalid register: R%d\n", index);
	exit(0);
}

void writeRegValue (short int index, short int value) {
	if (index >= 0 && index < NREGS) {
		while (writePort[0] == PORT_BUSY);
		registerFile[index] = value;
	}
	printf("Error: Tried to access invalid register: R%d\n", index);
	exit(0);
}
