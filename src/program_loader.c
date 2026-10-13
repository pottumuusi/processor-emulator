/*
 * program_loader.c
 */

/*
 * Headers of C standard library.
 */
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

/*
 * Headers of process-emulator.
 */
#include <program_loader.h>

#if 0
static bool
prepare_for_loading_arbitrary_program(void)
{
}
#endif

/*
 * Load a program that adds numbers 1 and 2, then continues with a verification
 * of result.
 *
 * Return value: Function successfully performed?
 */
bool
load_program_test_addition(void)
{
	const char *path_test_addition = "bin/test_addition";

	bool performance_success;

	performance_success = false;

	performance_success = load_arbitrary_program(path_test_addition);

	return performance_success;
}

/*
 * Return value: Function successfully performed?
 */
#define ERROR_MESSAGE_LOAD_ARBITRARY_PROGRAM \
	"Failed to load arbitrary program\n"
#define ERROR_MESSAGE_FCLOSE \
	"Failed to close file: %s (error: %s)\n"
#define ERROR_MESSAGE_FOPEN \
	"Failed to open file: %s (error: %s)\n"
bool
load_arbitrary_program(const char *program_file_path)
{
	// With hardware, a disk device driver would be required for loading a
	// program from a persistent storage.

	const char *mode_read_binary = "rb";

	FILE *program_file_handle;
	char *error_string;
	int32_t return_value;

	return_value = -1;
	program_file_handle = NULL;

	program_file_handle = fopen(program_file_path, mode_read_binary);
	error_string = strerror(errno);
	if (NULL == program_file_handle) {
		fprintf(stderr,
			ERROR_MESSAGE_FOPEN,
			program_file_path,
			error_string);

		goto fail;
	}

#if 0
	fread();
#endif

	return_value = fclose(program_file_handle);
	error_string = strerror(errno);
	if (0 != return_value) {
		fprintf(stderr,
			ERROR_MESSAGE_FCLOSE,
			program_file_path,
			error_string);

		goto fail;
	}

	return true;

fail:
	if (NULL != program_file_handle) {
		(void) fclose(program_file_handle);
	}

	fprintf(stderr, ERROR_MESSAGE_LOAD_ARBITRARY_PROGRAM);

	return false;
}
