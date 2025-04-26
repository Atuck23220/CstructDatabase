# Makefile for the CMSC257 Project2
#

# Make environment
CC=gcc
CFLAGS= -c -g -Wall

# Files
OBJECT_FILES=	cmsc257-p2.o p2-support.o

TARGET = p2

# Productions
all : $(TARGET)

$(TARGET) : $(OBJECT_FILES)
	$(CC)  $(OBJECT_FILES) -o $(TARGET)

cmsc257-p2.o : cmsc257-p2.c p2-support.h
	$(CC) $(CFLAGS) $< -o $@

p2-support.o : p2-support.c p2-support.h
	$(CC) $(CFLAGS) $< -o $@

clean :
	rm -v $(TARGET) $(OBJECT_FILES)
