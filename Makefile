CFLAGS := -Iinclude -std=c23 -Werror -Wpedantic

processor-emulator: src/main.c
	$(CC) $(CFLAGS) $^ -o processor-emulator
