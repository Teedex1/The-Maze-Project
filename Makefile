CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
LIBS = -lm -lSDL2

SRC_DIR = src
BUILD_DIR = build
TARGET = maze

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

.PHONY: all clean

all: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): $(OBJS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

run: $(BUILD_DIR)/$(TARGET)
	./$<

clean:
	rm -rf $(BUILD_DIR)/*


