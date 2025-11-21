CC = gcc
CFLAGS = -Wall -Iinclude -IUnity/src -fprofile-arcs -ftest-coverage
LDFLAGS = -fprofile-arcs -ftest-coverage
UNITY_SRC = Unity/src/unity.c

SRC_DIR = src
TEST_DIR = test

LIB_SRC = $(wildcard $(SRC_DIR)/*.c)
LIB_OBJ = $(LIB_SRC:.c=.o)

TEST_SRC = $(wildcard $(TEST_DIR)/*.c)

EXECUTABLE = main
TEST_EXECUTABLE = run_tests
LIB = libproject.a

.PHONY: all clean test coverage run

all: $(EXECUTABLE)

$(EXECUTABLE): main.o $(LIB)
	$(CC) $(CFLAGS) -o $@ main.o -L. -lproject -lm

$(LIB): $(LIB_OBJ)
	ar rcs $(LIB) $(LIB_OBJ)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)

$(TEST_EXECUTABLE): $(TEST_SRC) $(LIB)
	$(CC) $(CFLAGS) -o $@ $(UNITY_SRC) $(TEST_SRC) $(LIB) -lm

coverage: test
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory coverage_report

run: all
	@echo "Running ./$(EXECUTABLE)"
	@./$(EXECUTABLE)

clean:
	rm -f $(LIB_OBJ) $(EXECUTABLE) $(TEST_EXECUTABLE) *.o $(LIB)
	rm -f *.gcno *.gcda *.gcov coverage.info
	rm -rf coverage_report
