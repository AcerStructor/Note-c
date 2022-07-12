CC = gcc
PROGRAM_NAME = "Checking Byte Size of Each Data Types.exe"
SRC_FILES = CheckingByteSizeOfEachDataTypes.c
OBJECT_FILES = CheckingByteSizeOfEachDataTypes.o

Build: Compile Link

Link: $(OBJECT_FILES)
	$(CC) -o $(PROGRAM_NAME) $(OBJECT_FILES)

Compile: $(SRC_FILES)
	$(CC) -c  $(SRC_FILES)

.PHONY : clean
clean:
	del $(OBJECT_FILES) $(PROGRAM_NAME)