CC=g++
OBJDIR=obj
BINDIR=bin
EXEC=jogo
LDFLAGS = -Lsfml/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lm
CFLAGS = -Isfml/include -std=c++11 -Wall -pthread 
CSOURCE = $(wildcard src/*.cpp src/*/**.cpp)
OBJ=$(subst src, obj, $(CSOURCE:.cpp=.o))

.PHONY: default
default: dependencies $(CSOURCE) $(EXEC)

.PHONY: run
run: default execute

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) -o "$@"

$(OBJDIR)/%.o: src/%.cpp
	$(CC) $(CFLAGS) -o "$@" -c "$<"

.PHONY: debug
debug:
	$(CC) -c $(CSOURCE) $(LDFLAGS) $(CFLAGS) -ggdb
	mv *.o $(OBJDIR)/
	$(CC) $(OBJDIR)/*.o -o $(BINDIR)/$(EXEC)-debug $(LDFLAGS) $(SFML) $(CFLAGS)
	LD_LIBRARY_PATH=sfml/lib valgrind ./$(BINDIR)/$(EXEC)-debug --track-origins=yes --leak-check=full

.PHONY: clean
clean:
	rm -f $(OBJDIR)/* $(OBJDIR)/*/** $(BINDIR)/* *.o 2>/dev/null

.PHONY: dependencies
dependencies:
	sh dependencies.sh

.PHONY: execute
execute:
	mv $(EXEC) $(BINDIR)/
	LD_LIBRARY_PATH=sfml/lib ./$(BINDIR)/$(EXEC)