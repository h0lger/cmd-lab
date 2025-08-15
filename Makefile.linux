CC=g++
CFLAGS=-std=c++20
LDFLAGS=-lSDL2 -lSDL2_ttf -Wl,--no-as-needed
FILES=constants.cpp background.cpp dafont.cpp fps.cpp text.cpp main.cpp filelist.cpp
# Set the C++ standard version
all: main

main: main.cpp
	$(CC) $(CFLAGS) -g -o bin/main $(FILES) $(LDFLAGS)

clean:
	rm -f bin/main
