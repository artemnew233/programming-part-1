CC = gcc
CFLAGS = -Wall -g

ALL_PROGRAMS = task1_strcpy task2_fileops

all: $(ALL_PROGRAMS)
	@echo ""

task1_strcpy: task1_strcpy.c
	$(CC) $(CFLAGS) task1_strcpy.c -o task1_strcpy

task2_fileops: task2_fileops.c
	$(CC) $(CFLAGS) task2_fileops.c -o task2_fileops

run: all
	@echo "=== Task 1: strcpy Implementation ==="
	@./task1_strcpy
	@echo ""
	@echo "=== Task 2: File Operations ==="
	@./task2_fileops
	@echo ""

test: all
	@echo ""
	@./task1_strcpy
	@echo ""
	@./task2_fileops


clean:
	rm -f $(ALL_PROGRAMS)
	@echo "Cleaned up all compiled files!"

.PHONY: all test clean help
