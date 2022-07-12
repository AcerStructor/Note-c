CC = gcc
PROGRAM_NAME = "MathFunctions.exe"
SRC_FILES = MathFunctions.c
OBJECT_FILES = MathFunctions.o

Build: Compile Link

Link: $(OBJECT_FILES)
	$(CC) -o $(PROGRAM_NAME) $(OBJECT_FILES)

Compile: $(SRC_FILES)
	$(CC) -c -g $(SRC_FILES)

.PHONY : clean
clean:
	del $(OBJECT_FILES) $(PROGRAM_NAME)