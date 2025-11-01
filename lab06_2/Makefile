CC := gcc
CFLAGS := -Wall -Wextra -O2 -std=c11 -Iinclude
BUILD := build
SRC_DIR := src

SRCS := main.c $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst %.c,$(BUILD)/%.o,$(notdir $(SRCS)))

.PHONY: all exe clean preprocess asm

all: exe

exe: $(BUILD)/app

$(BUILD)/app: $(OBJS) | $(BUILD)
	$(CC) $(CFLAGS) $(OBJS) -o $@

# build build/foo.o from src/foo.c
$(BUILD)/%.o: $(SRC_DIR)/%.c | $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

# also allow building build/foo.o from ./foo.c (for root sources)
$(BUILD)/%.o: %.c | $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

asm: | $(BUILD)
	@for s in $(SRCS); do \
	  b=$$(basename $$s .c); \
	  echo " AS $(BUILD)/$$b.s"; \
	  $(CC) $(CFLAGS) -S $$s -o $(BUILD)/$$b.s; \
	done

run: exe
	./$(BUILD)/app

preprocess: | $(BUILD)
	@for s in $(SRCS); do \
	  b=$$(basename $$s .c); \
	  echo " PP $(BUILD)/$$b.i"; \
	  $(CC) $(CFLAGS) -E $$s -o $(BUILD)/$$b.i; \
	done

$(BUILD):
	mkdir -p $(BUILD)

clean:
	rm -rf $(BUILD)
