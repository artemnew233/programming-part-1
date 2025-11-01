CC := gcc
CFLAGS := -std=c11 -O2 -Wall -Wextra -Iinclude
LDFLAGS := -lm

BUILD := build
SRCDIRS := src .

SRCS := src/lab06_1.c main.c


BSRCS := $(notdir $(SRCS))

OBJS := $(patsubst %.c,$(BUILD)/%.o,$(BSRCS))

vpath %.c $(SRCDIRS)

.PHONY: all clean run

all: $(BUILD)/app


$(BUILD)/app: $(OBJS) | $(BUILD)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)


$(BUILD)/%.o: %.c | $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD):
	@mkdir -p $(BUILD)

run: all
	@echo "Running ./$(BUILD)/app"
	@./$(BUILD)/app

clean:
	@rm -rf $(BUILD)
