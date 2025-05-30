# All of the parameters
CC=gcc
CFLAGS=-g -Wall -std=c99
CCLINK=gcc
OBJS=main.o stack.o student.o
EXEC=prog.exe
RM=rm -f

# The execute rule
$(EXEC) : $(OBJS)
	$(CCLINK) $(OBJS) -o $(EXEC)

# All of the rules
stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

student.o: student.c student.h
	$(CC) $(CFLAGS) -c student.c

main.o: main.c stack.h student.h
	$(CC) $(CFLAGS) -c main.c

# The cleaning operation
clean:
	$(RM) *.o *.exe

