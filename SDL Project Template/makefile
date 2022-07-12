# Compiler Setup:
CC = gcc
SRCS_FILES = srcs/*.c
OBJECT_FILES = *.o
PROGRAM_NAME = "SDL Sample"
HEADER_FILES = -I headers

# SDL Setup:
SDL_INCLUDE = -I sdl/include
SDL_LIB = -L sdl/lib
SDL_DLL = -l mingw32 -l SDL2main -l SDL2

# Build All:
build: compile link

# Link:
link:
	$(CC) -o $(PROGRAM_NAME) $(OBJECT_FILES) $(SDL_LIB) $(SDL_DLL)

# Compile Srcs Files:
compile:
	$(CC) -c $(SRCS_FILES) $(HEADER_FILES) $(SDL_INCLUDE)

clean:
	del *.o *.exe