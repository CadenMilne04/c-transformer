
CC = gcc

SRC_DIR = src
TEST_FILE = test/test.c

SRC_FILES := $(shell find $(SRC_DIR) -name '*.c')

MAIN_BIN = main-bin
TEST_BIN = test-bin

.PHONY: run test clean

# Build main binary
run: $(MAIN_BIN)
	@./$(MAIN_BIN) || true
	@$(MAKE) clean

$(MAIN_BIN): $(SRC_FILES)
	$(CC) $^ -o $@

test: $(TEST_BIN)
	@./$(TEST_BIN) || true
	@$(MAKE) clean

SRC_NO_MAIN := $(filter-out $(SRC_DIR)/main.c, $(SRC_FILES))

$(TEST_BIN): $(TEST_FILE) $(SRC_NO_MAIN)
	$(CC) $^ -o $@

clean:
	@rm -f $(MAIN_BIN) $(TEST_BIN)
