CC := gcc
CFLAGS := -Wall -Wextra -O2 -std=c11 -Iinclude -MMD -MP
LDFLAGS := -lm

BUILD := build
SRC_DIR := src

SRCS := $(wildcard $(SRC_DIR)/*.c) main.c
OBJS := $(patsubst %.c,$(BUILD)/%.o,$(notdir $(SRCS)))
DEPS := $(OBJS:.o=.d)

vpath %.c . $(SRC_DIR)

.PHONY: all exe clean

all: exe

exe: $(BUILD)/app

$(BUILD)/app: $(OBJS) | $(BUILD)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD)/%.o: %.c | $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD):
	@mkdir -p $(BUILD)

clean:
	@rm -rf $(BUILD)

-include $(DEPS)
