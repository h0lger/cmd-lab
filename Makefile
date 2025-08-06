CC=clang++
CFLAGS=-I/opt/homebrew/include
LDFLAGS=-L/opt/homebrew/lib -lSDL2 -lSDL2_ttf -Wl,-rpath,/opt/homebrew/lib
FILES=constants.cpp background.cpp dafont.cpp fps.cpp text.cpp main.cpp filelist.cpp
all: main

main: main.cpp
	$(CC) $(CFLAGS) -g -o bin/main $(FILES) $(LDFLAGS)

clean:
	rm -f bin/main
