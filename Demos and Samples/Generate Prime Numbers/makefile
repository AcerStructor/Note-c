CC = gcc
PROGRAM_NAME = "Generate Prime Numbers.exe"
SRC_FILES = GeneratePrimeNumbers.c
OBJECT_FILES = GeneratePrimeNumbers.o

Build: Compile Link

Link: $(OBJECT_FILES)
	$(CC) -o $(PROGRAM_NAME) $(OBJECT_FILES)

Compile: $(SRC_FILES)
	$(CC) -c  $(SRC_FILES)

.PHONY : clean
clean:
	del $(OBJECT_FILES) $(PROGRAM_NAME)