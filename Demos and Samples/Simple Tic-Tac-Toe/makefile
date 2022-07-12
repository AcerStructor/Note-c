CC = gcc
PROGRAM_NAME = "TicTacToeConsole.exe"
HEADER_FILES = ConsoleDeco.h
SRC_FILES = TicTacToeConsole.c ConsoleDeco.c
OBJECT_FILES = TicTacToeConsole.o ConsoleDeco.o

Build: Compile Link

Link: $(OBJECT_FILES)
	$(CC) -o $(PROGRAM_NAME) $(OBJECT_FILES)

Compile: $(SRC_FILES) $(HEADER_FILES)
	$(CC) -c -O2 -s -DNDEBUG $(SRC_FILES)

.PHONY : clean
clean:
	del $(OBJECT_FILES) $(PROGRAM_NAME)