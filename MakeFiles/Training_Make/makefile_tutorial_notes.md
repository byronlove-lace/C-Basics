# MakeFile Tutorial

# Automatic Variables
- $@: target name
- $?: all prereqs newer than target
- $^: all preqs

# Wildcards
- * may be used in the target, prerequisites, or in the wildcard function.
- Danger: * may not be **directly** used in a variable definitions
- Danger: When * matches no files, it is left as it is (unless run in the wildcard function)
**Example:**
thing_wrong := *.o # Don't do this! '*' will not get expanded
thing_right := $(wildcard *.o)

% is really useful, but is somewhat confusing because of the variety of situations it can be used in.

- When used in "matching" mode, it matches one or more characters in a string. This match is called the stem.
- When used in "replacing" mode, it takes the stem that was matched and replaces that in a string.
- % is most often used in rule definitions and in some specific functions.

# Implicit Rules
- Compiling a C program: n.o is made automatically from n.c with a command of the form $(CC) -c $(CPPFLAGS) $(CFLAGS) $^ -o $@
- Compiling a C++ program: n.o is made automatically from n.cc or n.cpp with a command of the form $(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $^ -o $@
- Linking a single object file: n is made automatically from n.o by running the command $(CC) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) -o $@

CC = gcc # Flag for implicit rules
CFLAGS = -g # Flag for implicit rules. Turn on debug info

#Implicit rule #1: blah is built via the C linker implicit rule
#Implicit rule #2: blah.o is built via the C compilation implicit rule, because blah.c exists
blah: blah.o

blah.c:
	echo "int main() { return 0; }" > blah.c

clean:
	rm -f blah* 

# Static Rules (Better)
objects = foo.o bar.o all.o
all: $(objects)

# These files compile via implicit rules
foo.o: foo.c
bar.o: bar.c
all.o: all.c

all.c:
	echo "int main() { return 0; }" > all.c

%.c:
	touch $@

clean:
	rm -f *.c *.o all

objects = foo.o bar.o all.o
all: $(objects)

# These files compile via implicit rules
# Syntax - targets ...: target-pattern: prereq-patterns ...
# In the case of the first target, foo.o, the target-pattern matches foo.o and sets the "stem" to be "foo".
# It then replaces the '%' in prereq-patterns with that stem
$(objects): %.o: %.c

all.c:
	echo "int main() { return 0; }" > all.c

%.c:
	touch $@

clean:
	rm -f *.c *.o all

# Pattern Rules

Pattern rules are often used but quite confusing. You can look at them as two ways:

- A way to define your own implicit rules
- A simpler form of static pattern rules

#Define a pattern rule that compiles every .c file into a .o file
%.o : %.c
		$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

Pattern rules contain a '%' in the target. This '%' matches any nonempty string, and the other characters match themselves. ‘%’ in a prerequisite of a pattern rule stands for the same stem that was matched by the ‘%’ in the target.

Here's another example:

#Define a pattern rule that has no pattern in the prerequisites.
#This just creates empty .c files when needed.
%.c:
   touch $@

# Double-Colon Rules

Double-Colon Rules are rarely used, but allow multiple rules to be defined for the same target. If these were single colons, a warning would be printed and only the second set of commands would run.

all: blah

blah::
	echo "hello"

blah::
	echo "hello again"

# Command Execution

all: 
	cd ..
	# The cd above does not affect this line, because each command is effectively run in a new shell
	echo `pwd`

	# This cd command affects the next because they are on the same line
	cd ..;echo `pwd`

	# Same as above
	cd ..; \
	echo `pwd`

# Options

Error handling with -k, -i, and -

Add -k when running make to continue running even in the face of errors. Helpful if you want to see all the errors of Make at once.
Add a - before a command to suppress the error
Add -i to make to have this happen for every command.

# = & :=
There are two flavors of variables:

- recursive (use =) - only looks for the variables when the command is used, not when it's defined.
- simply expanded (use :=) - like normal imperative programming -- only those defined so far get expanded

#Recursive variable. This will print "later" below
one = one ${later_variable}
#Simply expanded variable. This will not print "later" below
two := two ${later_variable}

later_variable = later

all: 
	echo $(one)
	echo $(two)

Simply expanded (using :=) allows you to append to a variable. Recursive definitions will give an infinite loop error.

one = hello
# one gets defined as a simply expanded variable (:=) and thus can handle appending
one := ${one} there

all: 
	echo $(one)

?= only sets variables if they have not yet been set

one = hello
one ?= will not be set
two ?= will be set

all: 
	echo $(one)
	echo $(two)

Spaces at the end of a line are not stripped, but those at the start are. To make a variable with a single space, use $(nullstring)

with_spaces = hello   # with_spaces has many spaces after "hello"
after = $(with_spaces)there

nullstring =
space = $(nullstring) # Make a variable with a single space.

all: 
	echo "$(after)"
	echo start"$(space)"end

An undefined variable is actually an empty string!

all: 
	# Undefined variables are just empty strings!
	echo $(nowhere)

Use += to append

foo := start
foo += more

all: 
	echo $(foo)
