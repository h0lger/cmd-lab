CC=g++
CFLAGS=
LDFLAGS=-lSDL2 -lSDL2_ttf -Wl,--no-as-needed
all: main

main: main.cpp
	$(CC) $(CFLAGS) -g -o main constants.cpp background.cpp dafont.cpp fps.cpp text.cpp main.cpp $(LDFLAGS)

clean:
	rm -f main
