CC = gcc
CFLAGS = -Wall -g

ALL_PROGRAMS = lab11_task1 lab11_task2 lab11_bonus

all: $(ALL_PROGRAMS)
	@echo ""
	@echo "========================================="
	@echo "   Lab 11 - All programs compiled!     "
	@echo "           VARIANT 12                   "
	@echo "========================================="
	@echo ""

lab11_task1: lab11_task1.c
	$(CC) $(CFLAGS) lab11_task1.c -o lab11_task1

lab11_task2: lab11_task2.c
	$(CC) $(CFLAGS) lab11_task2.c -o lab11_task2

lab11_bonus: lab11_bonus.c
	$(CC) $(CFLAGS) lab11_bonus.c -o lab11_bonus

run: all
	@echo "=== Task 1: Digit Difference ==="
	@echo "Enter a number to test (e.g., 12345):"
	@./lab11_task1
	@echo ""
	@echo "=== Task 2: Pyramid ==="
	@echo "Enter pyramid height (e.g., 5):"
	@./lab11_task2
	@echo ""
	@echo "=== Bonus: Performance Comparison ==="
	@./lab11_bonus
	@echo "========================================="
	@echo "         All programs completed!        "
	@echo "========================================="

test: all
	@echo ""
	@echo "========================================="
	@echo "      Testing Lab 11 programs...       "
	@echo "========================================="
	@echo "========================================="
	@echo "            Tests complete!             "
	@echo "========================================="

clean:
	rm -f $(ALL_PROGRAMS)
	@echo "Cleaned up all compiled files!"

.PHONY: all test clean help
