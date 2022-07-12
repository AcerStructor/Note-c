CC = gcc
PROGRAM_NAME = "Guess My Age.exe"
SRC_FILES = main.c ConsoleDeco.c
HEADER_FILES = ConsoleDeco.h
OBJECT_FILES = main.o ConsoleDeco.o

Build: Compile Link

Link: $(OBJECT_FILES)
	$(CC) -o $(PROGRAM_NAME) $(OBJECT_FILES)

Compile: $(SRC_FILES) $(HEADER_FILES)
	$(CC) -c  $(SRC_FILES)

.PHONY : clean
clean:
	del $(OBJECT_FILES) $(PROGRAM_NAME)