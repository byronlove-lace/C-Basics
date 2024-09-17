CC = gcc
# -I dir will include dir in folders to be searched for header files in preprocessing
#  Here it includes only the current directory
INCDIRS = -I.

# -Onum determines the level of optimisation (by defualt, this is set to 0)
OPT = -O0
CFLAGS = -Wall -Wextra -g $(INCDIRS) $(OPT)

CFILES = x.c y.c
OBJECTS = x.o y.o

BINARY = bin

# when you type 'make' it will run the first rule. By convention, this rule is all.
all: $(BINARY)
	

# if you want to build bin, then all objects need to exist already
$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^

# make has regular expressions
# % is a wildcard
# if I want to build x.o then I need x.c / y.o:y.c
# @ is the target(left) so in the above context @ == BINARY == bin
# NOTE: $@ is the target if there are multiple targets for a
# rule then $@ will run for each
# all: f1.o f2.o
# f1.o f2.0
# echo $@ // make: it will run for each 
# $@: $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(BINARY) *.o
