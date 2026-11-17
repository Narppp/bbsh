CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wpedantic -Iinclude -O2 -g3
SRC_DIR = src
BUILD_DIR = normal_build
DEBUG_FLAGS = -fsanitize=address,undefined

SRCS = $(wildcard src/*.c)

NORM_OBJ_DIR = obj/norm_obj
NORM_OBJS = $(SRCS:$(SRC_DIR)/%.c=$(NORM_OBJ_DIR)/%.o)

NORM_BIN = $(BUILD_DIR)/norm_bbsh

all: $(NORM_BIN)

run: $(NORM_BIN)
	@clear
	@./$(NORM_BIN)

gdb: $(NORM_BIN)
	@clear
	@gdb ./$(NORM_BIN)

sanitize: $(NORM_BIN)
	@clear
	@$(DEBUG_FLAGS) ./$(NORM_BIN)

valgrind: $(NORM_BIN)
	@clear
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NORM_BIN)

$(NORM_BIN): $(NORM_OBJS) | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(NORM_OBJS) -o $(NORM_BIN)

$(NORM_OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(NORM_OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR) $(NORM_OBJ_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(NORM_OBJ_DIR) $(BUILD_DIR)

help:
	@echo "Available commands:"
	@echo "make - Build the shell"
	@echo "make run - Build AND Run the shell"
	@echo "make clean - Deletes all files for proper restart"
	@echo "make sanitize - Checks ASan for mem leak"
	@echo "make gdb - Runs gdb for debugging"
	@echo "make valgrind - Runs valgrind for easier bug traces"

.PHONY: all clean run help sanitize gdb valgrind
