

BIN = a.out
FLAGS = -Wall -std=c99 -lm

clean: run
	rm  $(BIN)

run: $(BIN)
	./$(BIN) $(arg)

$(BIN): f2sp.c 
	gcc -o $(BIN) f2sp.c $(FLAGS)

