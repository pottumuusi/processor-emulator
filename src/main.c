#include <stdio.h>
#include <stdint.h>

#define CPU_INSTRUCTION_ADD 0x1
#define CPU_INSTRUCTION_SUB 0x2
#define CPU_INSTRUCTION_MUL 0x3
#define CPU_INSTRUCTION_DIV 0x4

#define MAIN_MEMORY_BANK_AMOUNT 1024

struct cpu_instruction_operand_tuple {
	uint8_t left;
	uint8_t right;
};

struct cpu_instruction {
	uint8_t identifier;
};

struct cpu_register {
	uint8_t accumulator;
	uint8_t temporary;
	uint8_t counter;
	uint8_t index;
};

struct main_memory {
	uint8_t bank[MAIN_MEMORY_BANK_AMOUNT]; 
};

// What should processor do first?
// Where are the instructions?
//
// So the processor should likely have some startup logic. A hardcoded
// program. This gets the processor ready for loading a program to main
// memory. The powerup of a motherboard is out of scope of the initial
// plan.
//
// 

static bool
cpu_prepare_for_loading_arbitrary_program(void)
{
}

static bool
cpu_load_arbitrary_program(void)
{
}

int
main(void)
{
	cpu_prepare_for_loading_arbitrary_program();

	cpu_load_arbitrary_program();

	printf("1, 2, 3\n");

	return 0;
}
