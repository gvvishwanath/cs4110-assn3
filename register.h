#ifndef REGISTER_H
#define REGISTER_H

#include "instruction.h"

#define NREGS 16
#define NREAD 2
#define NWRITE 1

#define PORT_FREE 0
#define PORT_BUSY 1

short int registerFile[NREGS];
short int readPorts[NREAD];
short int writePorts[NWRITE];
registerFile[0] = 0;

void initPorts (void);
void initRegFile (char *regFile);

short int getRegIndex (InstructionType instr, short int opNum);
void setRegIndex (InstructionType instr, short int opNum, char *regWord);

short int readRegValue (short int index);
void writeRegValue (short int index, short int value);

#endif
