SOURCE_DIRECTORY := src

SOURCE_FILES := $(wildcard $(SOURCE_DIRECTORY)/*.c)

# TODO decide whether to add -c option
# https://en.wikipedia.org/wiki/Object_file
CFLAGS := -Iinclude -std=c23 -Werror -Wpedantic

# TODO
# test build targets:
# * unit tests
# * end-to-end tests
# * static analysis
# * memory leak detection
# * performance analysis

processor-emulator: $(SOURCE_FILES)
	$(CC) $(CFLAGS) $^ -o processor-emulator
