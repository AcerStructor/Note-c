CC = gcc
PROGRAM_NAME = "Determine Amount of Pay.exe"
SRC_FILES = DetermineAmountOfPay.c
OBJECT_FILES = DetermineAmountOfPay.o

Build: Compile Link

Link: $(OBJECT_FILES)
	$(CC) -o $(PROGRAM_NAME) $(OBJECT_FILES)

Compile: $(SRC_FILES)
	$(CC) -c  $(SRC_FILES)

.PHONY : clean
clean:
	del $(OBJECT_FILES) $(PROGRAM_NAME)