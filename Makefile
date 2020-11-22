# Makefile for starter by Phil Rogers
#
# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

# the build target executable:
TARGET = starter
TARGETEXE = $(TARGET).exe

all: $(TARGETEXE)

$(TARGETEXE): $(TARGET).cpp $(TARGET).h
	$(CC) $(CFLAGS) -o $(TARGETEXE) $(TARGET).cpp

clean:
	$(RM) $(TARGETEXE)





