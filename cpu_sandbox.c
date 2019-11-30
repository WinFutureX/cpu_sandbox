/*
 * 
 *  useless cpu core
 *  copyfuck kelsey boey, 2019
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>	// for some randomness

// opcode types (0x0000 is undefined)
#define SHL 0x1000	// shift left
#define SHR 0x2000	// shift right
#define PSH 0x3000	// push
#define POP 0x4000	// pop
#define BRA 0x5000	// branch
#define TRP 0x6000	// trap
#define SYC 0x7000	// system call
#define RST 0x8000	// reset
#define LEA 0x9000	// load effective address
#define MOV 0xa000	// move
#define ADD 0xb000	// add
#define SUB 0xc000	// subtract
#define MUL 0xd000	// multiply
#define DIV 0xe000	// divide
#define JMP 0xf000	// jump

// cpu state
struct cpustate
{
	const char	*model;
	uint32_t	regs[16];
	uint8_t		flags[6];	// carry, overflow, underflow, equal, more, less? (CVUEML)
	uint32_t	pc;
	uint8_t		running;
} cpustate;

// system devices
struct devices
{
	uint16_t	ram[4];
} devices;

// function prototypes
void decodeinstr(uint16_t addr[], struct cpustate * state);

// code start
int main(int argc, char * argv[])
{
	// reset cpu
	srand(time(NULL));	// random seed
	printf("CPU reset\n");
	// init regs, flags pc and fill ram
	struct cpustate cpu;
	struct devices dev = {.ram = rand(), rand(), rand(), rand()};
	cpu.running = 1;
	cpu.model = "SillyCPU v0.01";
	cpu.regs[0] = 0;
	cpu.regs[1] = 0;
	cpu.regs[2] = 0;
	cpu.regs[3] = 0;
	cpu.regs[4] = 0;
	cpu.regs[5] = 0;
	cpu.regs[6] = 0;
	cpu.regs[7] = 0;
	cpu.regs[8] = 0;
	cpu.regs[9] = 0;
	cpu.regs[10] = 0;
	cpu.regs[11] = 0;
	cpu.regs[12] = 0;
	cpu.regs[13] = 0;
	cpu.regs[14] = 0;
	cpu.regs[15] = 0;
	cpu.flags[0] = 0;
	cpu.flags[1] = 0;
	cpu.flags[2] = 0;
	cpu.flags[3] = 0;
	cpu.flags[4] = 0;
	cpu.flags[5] = 0;
	cpu.pc = 0;
	printf("Initialising %s\n", cpu.model);
	/*
	for (int regno = 0; regno <= 15; regno++)
	{
		printf("Reg %d: 0x%08x\n", regno, cpu.regs[regno]);
	}
	*/
	printf("reg init\n");
	/*
	for (int flagno = 0; flagno <= 5; flagno++)
	{
		printf("Flag %d: 0x%x\n", flagno, cpu.flags[flagno]);
	}
	*/
	printf("flag init\n");
	printf("PC: 0x%08x\n", cpu.pc);
	while (cpu.running)
	{
		decodeinstr(dev.ram, &cpu);
	} 
	printf("Exiting...\n");
	return 0;
}

// decode instructions
void decodeinstr(uint16_t addr[], struct cpustate * state)
{
	printf("warning: decode not yet fully implemented\n");
	for (int opno = 0; opno <= 3; opno++)
	{
		printf("Opcode 0x%04x at address 0x%08x\n", addr[opno], state->pc);
		if (addr[opno] >> 12 == SHL >> 12) // shift left
		{
			printf("SHL instruction encountered\n");
		} else if (addr[opno] >> 12 == SHR >> 12) // shift right
		{
			printf("SHR instruction encountered\n");
		} else if (addr[opno] >> 12 == PSH >> 12) // push
		{
			printf("PSH instruction encountered\n");
		} else if (addr[opno] >> 12 == POP >> 12) // pop
		{
			printf("POP instruction encountered\n");
		} else if (addr[opno] >> 12 == BRA >> 12) // branch
		{
			printf("BRA instruction encountered\n");
		} else if (addr[opno] >> 12 == TRP >> 12) // trap
		{
			printf("TRP instruction encountered\n");
		} else if (addr[opno] >> 12 == SYC >> 12) // system call
		{
			printf("SYC instruction encountered\n");
		} else if (addr[opno] >> 12 == RST >> 12) // reset
		{
			printf("RST instruction encountered\n");
		} else if (addr[opno] >> 12 == LEA >> 12) // load effective address
		{
			printf("LEA instruction encountered\n");
		} else if (addr[opno] >> 12 == MOV >> 12) // move
		{
			printf("MOV instruction encountered\n");
		} else if (addr[opno] >> 12 == ADD >> 12) // add
		{
			printf("ADD instruction encountered\n");
		} else if (addr[opno] >> 12 == SUB >> 12) // subtract
		{
			printf("SUB instruction encountered\n");
		} else if (addr[opno] >> 12 == MUL >> 12) // multiply
		{
			printf("MUL instruction encountered\n");
		} else if (addr[opno] >> 12 == DIV >> 12) // divide
		{
			printf("DIV instruction encountered\n");
		} else if (addr[opno] >> 12 == JMP >> 12) // jump
		{
			printf("JMP instruction encountered\n");
		} else // undefined
		{
			printf("Undefined instruction - shutting down\n");
			break;
		}
		state->pc += 2; // increment pc
	}
	state->running = 0;
	printf("CPU shutdown\n");
	return;
}
