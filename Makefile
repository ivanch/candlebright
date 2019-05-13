CC=g++
OBJDIR=obj
BINDIR=bin
COMPILER_FLAGS=	-std=c++11 -lm -lsfml-graphics -lsfml-window -lsfml-system
C_SOURCE = $(filter-out src/main.cpp, $(wildcard src/*.cpp))
BUILD_SOURCE = $(wildcard $(OBJDIR)/*.o)

default: main

compile: clean
	$(CC) -c $(C_SOURCE) src/main.cpp $(COMPILER_FLAGS)
	mv *.o $(OBJDIR)/

main: clean compile
	$(CC) $(BUILD_SOURCE) -o $(BINDIR)/jogo $(COMPILER_FLAGS)

clean:
	rm -rf $(OBJDIR)/* $(BINDIR)/* *.o

execute:
	./$(BINDIR)/jogo
	
run: main execute