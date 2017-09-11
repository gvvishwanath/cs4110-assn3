#define CSTART 0
#define CEND (CSTART+2)
#define CSIZE (CEND-CSTART+1)

#define ISTART (CEND+1)
#define IEND ISTART
#define ISIZE (IEND-ISTART+1)

#define OP1START IEND+1
#define OP1END (OP1START+3)
#define OP1SIZE (OP1END-OP1START+1)

#define OP2START (OP1END+1)
#define OP2END (OP2START+3)
#define OP2SIZE (OP2END-OP2START+1)

#define OP3START (OP2END+1)
#define OP3END (OP3START+3)
#define OP3SIZE (OP3END-OP3START+1)

struct instruction {
	int opcode:CSIZE,
	int immFlag:ISIZE,
	int op1:OP1SIZE,
	int op2:OP2SIZE,
	int op3:OP3SIZE
};

typedef struct instruction InstructionType;
