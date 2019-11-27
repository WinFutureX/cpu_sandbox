#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>	// for some randomness

// some important things first
#define MOV 0xa000
#define ADD 0xb000
#define SUB 0xc000
#define MUL 0xd000
#define DIV 0xe000
#define JMP 0xf000

struct cpustate
{
	const char	*model;
	uint32_t	regs[8];
	uint8_t		flags[6];
	uint32_t	pc;
	uint16_t	op;
};

void decodeinstr(uint32_t addr, struct cpustate * state);

// code start
int main()
{
	// reset cpu
	srand(time(NULL));	// random seed
	printf("CPU reset\n");
	// fill regs with garbage, randomise flags and init pc
	struct cpustate cpu;
	cpu.model = "SillyCPU v0.01";
	cpu.regs[0] = rand();
	cpu.regs[1] = rand();
	cpu.regs[2] = rand();
	cpu.regs[3] = rand();
	cpu.regs[4] = rand();
	cpu.regs[5] = rand();
	cpu.regs[6] = rand();
	cpu.regs[7] = rand();
	cpu.flags[0] = rand() & 1;
	cpu.flags[1] = rand() & 1;
	cpu.flags[2] = rand() & 1;
	cpu.flags[3] = rand() & 1;
	cpu.flags[4] = rand() & 1;
	cpu.flags[5] = rand() & 1;
	cpu.pc = -1;
	cpu.op = rand();
	printf("Initialising %s\n", cpu.model);
	for (int regno = 0; regno <= 7; regno++)
	{
		printf("Reg %d: 0x%08x\n", regno, cpu.regs[regno]);
	}
	for (int flagno = 0; flagno <= 5; flagno++)
	{
		printf("Flag %d: 0x%x\n", flagno, cpu.flags[flagno]);
	}
	printf("PC: 0x%08x\n", cpu.pc);
	decodeinstr(cpu.pc, &cpu);
	printf("Exiting...\n");
}

void decodeinstr(uint32_t addr, struct cpustate * state)
{
	printf("warning: decode not yet fully implemented\n");
	printf("Opcode: 0x%x\n", state->op);
	if (state->op >> 12 == MOV >> 12)
	{
		printf("MOV instruction encountered\n");
	} else if (state->op >> 12 == ADD >> 12)
	{
		printf("ADD instruction encountered\n");
	} else if (state->op >> 12 == SUB >> 12)
	{
		printf("SUB instruction encountered\n");
	} else if (state->op >> 12 == MUL >> 12)
	{
		printf("MUL instruction encountered\n");
	} else if (state->op >> 12 == DIV >> 12)
	{
		printf("DIV instruction encountered\n");
	} else if (state->op >> 12 == JMP >> 12)
	{
		printf("JMP instruction encountered\n");
	} else
	{
		printf("Undefined instruction\n");
	}
	return;
}
