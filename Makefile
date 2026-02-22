# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -Iinclude

# Directories
SRC_DIR = src
BUILD_DIR = build

# Target executable
TARGET = $(BUILD_DIR)/main

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

# Default target
all: $(TARGET)

# Link object files into final binary
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean build files
clean:
	rm -rf $(BUILD_DIR)

# Phony targets
.PHONY: all clean
