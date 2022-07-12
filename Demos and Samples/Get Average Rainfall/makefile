CC = gcc
PROGRAM_NAME = "Get Average Rainfall.exe"
SRC_FILES = GetAverageRainfall.c
OBJECT_FILES = GetAverageRainfall.o

Build: Compile Link

Link: $(OBJECT_FILES)
	$(CC) -o $(PROGRAM_NAME) $(OBJECT_FILES)

Compile: $(SRC_FILES)
	$(CC) -c  $(SRC_FILES)

.PHONY : clean
clean:
	del $(OBJECT_FILES) $(PROGRAM_NAME)