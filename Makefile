SRC_DIR=src
INCLUDE_DIR=include
TEST_DIR=tests
BIN_DIR=bin
TEST_BIN_DIR=$(TEST_DIR)/$(BIN_DIR)

LIBS = gtk+-3.0

CC=gcc
CFLAGS += -Wall -g -I$(INCLUDE_DIR)/
CFLAGS := $(shell pkg-config --cflags $(LIBS)) $(CFLAGS)
LDLIBS := $(shell pkg-config --libs $(LIBS)) $(LDLIBS)

COMPILE=$(CC) $(CFLAGS) -c $^ -o $@
LINK_EXE=$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)


SRC_FILES=$(wildcard $(SRC_DIR)/*.c)								
SRC_OBJS=$(patsubst $(SRC_DIR)/%.c,$(BIN_DIR)/%.o, $(SRC_FILES))

TARGET = $(wildcard $(SRC_OBJS)/*.o

TEST_FILES=$(wildcard $(TEST_DIR)/*.c)
TEST_OBJS=$(patsubst $(TEST_DIR)/%.c,$(TEST_BIN_DIR)/%.o, $(TEST_FILES))
TEST_EXE=$(patsubst %.o,%, $(TEST_OBJS))
TEST_TARGETS=$(patsubst $(TEST_DIR)/%.c,$(TEST_BIN_DIR)/%, $(TEST_FILES))

$(shell if [ ! -d "${TEST_BIN_DIR}" ]; then mkdir -p ${TEST_BIN_DIR}; fi;)
$(shell if [ ! -d "${BIN_DIR}" ]; then mkdir -p ${BIN_DIR}; fi;)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	$(COMPILE)

$(TEST_BIN_DIR)/%.o: $(TEST_DIR)/%.c
	$(COMPILE)

.phony: all src tests clean clean-src clean-tests 

all: src tests window 

src: $(SRC_OBJS)

tests: $(TEST_TARGETS)


clean-test:
	$(RM) $(TEST_EXE) $(TEST_OBJS)


clean-src:
	$(RM) $(SRC_OBJS)

clean:
	rm -rf $(BIN_DIR)/*



window: $(SRC_OBJS) 
	$(LINK_EXE)


define EXE_OBJS
	$(patsubst %, %.o, $(1)) $(patsubst %, $(BIN_DIR)/%.o, $(2))
endef
