CC = gcc
CFLAGS = -Wall -Iinclude -IUnity/src  -fprofile-arcs -ftest-coverage
LDFLAGS = -fprofile-arcs -ftest-coverage
SRC_DIR = src
TEST_DIR = test
UNITY_SRC = Unity/src/unity.c

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(SRC_FILES:.c=.o)
TEST_FILES = $(wildcard $(TEST_DIR)/*.c)

EXECUTABLE = main
TEST_EXECUTABLE = run_tests
LIB = libproject.a

.PHONY: all clean test coverage run

all: $(EXECUTABLE)

$(EXECUTABLE): main.o $(LIB)
	$(CC) $(CFLAGS) -o $@ main.o -L. -lproject -lm

$(LIB): $(OBJ_FILES)
	ar rcs $(LIB) $(OBJ_FILES)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)

$(TEST_EXECUTABLE): $(TEST_FILES) $(LIB)
	$(CC) $(CFLAGS) -o $@ $(UNITY_SRC) $(TEST_FILES) $(LIB) -lm

coverage: test
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory coverage_report

run: all
	@echo "Running ./$(EXECUTABLE)"
	@./$(EXECUTABLE)

clean:
	rm -f $(OBJ_FILES) $(EXECUTABLE) $(TEST_EXECUTABLE) *.o $(LIB)
	rm -f *.gcno *.gcda *.gcov coverage.info
	rm -rf coverage_report
