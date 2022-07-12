CC = gcc
PROGRAM_NAME = "Minutes To Days and Years.exe"
SRC_FILES = MinutesToDaysandYears.c
OBJECT_FILES = MinutesToDaysandYears.o

Build: Compile Link

Link: $(OBJECT_FILES)
	$(CC) -o $(PROGRAM_NAME) $(OBJECT_FILES)

Compile: $(SRC_FILES)
	$(CC) -c  $(SRC_FILES)

.PHONY : clean
clean:
	del $(OBJECT_FILES) $(PROGRAM_NAME)