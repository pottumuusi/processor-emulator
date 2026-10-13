/*
 * main.c
 */

// TODO c-logging library utilization

/*
 * Headers of C standard library.
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>

/*
 * Headers of process-emulator.
 */
#include <program_loader.h>

// TODO How many instructions will be supported?
#define CPU_INSTRUCTION_ADD 0x1
#define CPU_INSTRUCTION_SUB 0x2
#define CPU_INSTRUCTION_MUL 0x3
#define CPU_INSTRUCTION_DIV 0x4

// TODO
// * memory instructions
// * comparison instruction(s)
// * branch instructions

#define MAIN_MEMORY_BANK_AMOUNT 1024

// TODO Structure packing?

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

// TODO
//
// What should processor do first?
// Where are the instructions?
//
// So the processor should likely have some startup logic. A hardcoded
// program. This gets the processor ready for loading a program to main
// memory. The powerup of a motherboard is out of scope of the initial
// plan.

int
main(void)
{
	bool performance_success;

	performance_success = false;

	performance_success = load_program_test_addition();
	if (false == performance_success) {
		goto fail;
	}

	printf("Exiting with success\n");

	return 0;

fail:
	fprintf(stderr, "Exiting with failure\n");

	return 1;
}
