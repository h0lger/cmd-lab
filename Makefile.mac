CC=clang++
CFLAGS=-I/opt/homebrew/include
LDFLAGS=-L/opt/homebrew/lib -lSDL2 -lSDL2_ttf -Wl,-rpath,/opt/homebrew/lib
all: main

main: main.cpp
	$(CC) $(CFLAGS) -g -o main background.cpp dafont.cpp fps.cpp text.cpp main.cpp $(LDFLAGS)

clean:
	rm -f main
