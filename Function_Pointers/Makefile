.PHONY: clean all

CC = g++
INCDIRS = -I.
OPT = -O0
CFLAGS = -Wall -Wextra -g $(INCDIRS) $(OPT)
BIN = bin
SOURCE = src
SOURCES := $(wildcard $(SOURCE)/*.cpp)
EXES    := $(patsubst $(SOURCE)/%.cpp,%,$(SOURCES))

all: $(EXES)

$(EXES): %: $(SOURCE)/%.cpp
	$(CC) $(CFLAGS) $< -o $(BIN)/$@

clean: 
	$(foreach exe, $(EXES), rm -f $(BIN)/$(exe);)
