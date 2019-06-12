CC=g++
OBJDIR=obj
BINDIR=bin
COMPILER_FLAGS=	-std=c++11 -lm -Isfml/include -Lsfml/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -pthread -Wall
C_SOURCE = $(filter-out src/main.cpp, $(wildcard src/*.cpp))
BUILD_SOURCE = $(wildcard $(OBJDIR)/*.o)

default: main

compile: clean dependencies
	$(CC) -c $(C_SOURCE) src/main.cpp $(COMPILER_FLAGS)
	mv *.o $(OBJDIR)/

main: clean compile
	$(CC) $(BUILD_SOURCE) -o $(BINDIR)/jogo $(COMPILER_FLAGS)

clean:
	rm -rf $(OBJDIR)/* $(BINDIR)/* *.o

execute:
	LD_LIBRARY_PATH=sfml/lib ./$(BINDIR)/jogo

debug:
	$(CC) -c $(C_SOURCE) src/main.cpp $(COMPILER_FLAGS) -ggdb
	mv *.o $(OBJDIR)/
	$(CC) $(BUILD_SOURCE) -o $(BINDIR)/jogo-debug $(COMPILER_FLAGS)
	LD_LIBRARY_PATH=sfml/lib valgrind ./$(BINDIR)/jogo-debug

run: main execute

dependencies:
	sh dependencies.sh
