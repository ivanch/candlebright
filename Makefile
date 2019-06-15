CC=g++
OBJDIR=obj
BINDIR=bin
EXEC=jogo
LDFLAGS = -Lsfml/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lm
CFLAGS = -Isfml/include -std=c++11 -Wall -pthread 
CSOURCE = $(wildcard src/*.cpp)
OBJ=$(subst src, obj, $(CSOURCE:.cpp=.o))
VAL_FLAGS = --track-origins=yes --leak-check=full

.PHONY: default
default: $(SRC) $(EXEC)

.PHONY: run
run: default execute

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) -o "$@"

$(OBJDIR)/%.o: src/%.cpp
	$(CC) $(CFLAGS) -o "$@" -c "$<"

.PHONY: debug
debug:
	$(CC) -c $(CSOURCE) $(COMPILER_FLAGS) $(SFML) -ggdb
	mv *.o $(OBJDIR)/
	$(CC) $(OBJ) -o $(BINDIR)/$(EXEC)-debug $(COMPILER_FLAGS) $(SFML) $(CFLAGS)
	LD_LIBRARY_PATH=sfml/lib valgrind ./$(BINDIR)/$(EXEC)-debug $(VAL_FLAGS)

.PHONY: clean
clean:
	rm -rf $(OBJDIR)/* $(BINDIR)/* *.o

.PHONY: dependencies
dependencies:
	sh dependencies.sh

.PHONY: execute
execute:
	mv $(EXEC) $(BINDIR)/
	LD_LIBRARY_PATH=sfml/lib ./$(BINDIR)/$(EXEC)