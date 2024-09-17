BINARY = bin
CODEDIRS = . lib
INCDIRS = . ./include/ # can be a list.

CC = gcc
OPT = -O0
# generate files that encode make rules for .h dependencies.
DEPFLAGS = -MP -MD
# automatically add the -I onto each include directory
# for each directory in INDIRS, run -I 'directory' ... 
CFLAGS = -Wall -Werror -g $(foreach D, $(INCDIRS), -I $(D)) $(OPT) $(DEPFLAGS)

# for-style iteration (foreach) and regular expression completions (wildcard)
# for each directory in CODEDIRS find each .c file inside them
CFILES = $(foreach D, $(CODEDIRS), $(wildcard $(D)/*.c))

# regular expression replacment 
OBJECT = $(patsubst %.c, %.o, $(CFLIES))
DEPFILES = $(patsubst %.c, %.d, $(CFLIES))

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^

# only want .c file dependency here, thus $< instead of $^
%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<
