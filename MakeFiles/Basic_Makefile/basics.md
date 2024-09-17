# What is a makefile?
    It's a type of build system.

## So, what's a build system?
    1. They automate the linking of source files into exes 
    2. Processes only what is necessary (recomplie only the chaged portion of the source code
    3. Avoid redundant/copied code 

    * sh scripts fail to meet requirements 2 and 3. Therefore, we shouldn't use them as a build system.

## Build Rules
    1. The left is the build rule: what is going to be built
    2. The right side includes the dependencies
    3. buildTarget: dependency
    4. We always include an all: x and a clean: \n clean

## Selective Compilation:
Make will only run commands if the file in the command has changed.

## Dependency List:
It's essentially a codified dependency list.
