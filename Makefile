# compile with gcc

INCLUDE := ./include
SRC := ./src
BUILD := ./build
CC=g++

# Compiler options:
#
CFLAGS = -g -Wall -Werror

# Linker options:
#
# -lm: link with the math library
LDFLAGS += -lm

# set the name of the executable file to compile here
EXEC = main

SRCS := $(shell find $(SRC) -name '*.cpp')
OBJS := $(SRCS:$(SRC)/%.c=$(SRC)/%.opp)


$(SRC)/%.opp: $(SRC)/%.cpp
	$(CCPP) $(CPPFLAGS) -c $< -o $@
	mv $@ $(BUILD)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(EXEC)

PHONY clean:
	rm -f $(BUILD)/*.opp $(EXEC)

run: $(EXEC)
	./$(EXEC) test.txt