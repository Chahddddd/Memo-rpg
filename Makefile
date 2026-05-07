CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC = src/main.c src/board.c src/player.c
BUILD_DIR = build
TARGET = $(BUILD_DIR)/program

all: $(TARGET)

$(TARGET): $(SRC)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all run clean