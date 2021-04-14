FILE=poker.out
BIN=./bin
SRC=./src
INC=./inc
UNITY=./unity
TEST=./test
OBJ=$(BIN)/main.o $(BIN)/poker.o

all: $(FILE)

$(FILE):$(OBJ)
	gcc -o $@ $^

$(BIN)/main.o:main.c
	gcc -o $(BIN)/main.o -c $^


$(BIN)/poker.o:$(SRC)/poker.c $(INC)/poker.h
	gcc -o $(BIN)/poker.o -c $(SRC)/poker.c

test: $(BIN)/poker.o
	gcc $(TEST)/tests.c $(SRC)/poker.c  $(UNITY)/unity.c

clean:
	rm -rf *.out $(BIN)/*.o
