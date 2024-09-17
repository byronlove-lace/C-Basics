.PHONY: all
# .PHONY will force make not to look for file called all
# it will ALWAYS run all, even if some lunatic included
# a file named all

CC = g++
INCDIRS = -I.
OPT = -O0
CFLAGS = -Wall -Wextra -g $(INCDIRS) $(OPT)
BIN = bin
EXES = costs_and_revenue friend_functions operator_overloading_with_friends

all: $(EXES)

$(EXES): %: %.cpp
	$(CC) $(CFLAGS) $^ -o $(BIN)/$@

.PHONY: clean

clean: 
	$(foreach exe, $(EXES), rm -f $(BIN)/$(exe);)
