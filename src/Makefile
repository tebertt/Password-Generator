# Author:      Troy Ebert
# Filename:    Makefile
# Description: Compiles generate using gcc

TARGET  = generate
SOURCES = main.c flags.c
OBJECTS = $(SOURCES:.c=.o)

CXX     = gcc
FLAGS   = -std=c99 -Wall

all: $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS)

$(OBJECTS) : $(SOURCES)
	$(CXX) -c $(FLAGS) $(SOURCES)

clean :
	rm -f $(OBJECTS)

spotless : clean
	rm -f $(TARGET)

.PHONY : all clean spotless