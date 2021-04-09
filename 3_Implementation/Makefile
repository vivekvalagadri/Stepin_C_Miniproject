FILE=poker.out
BIN=./bin
SRC=./src
INC=./inc
OBJ=$(BIN)/main.o $(BIN)/poker.o

all: $(FILE)

$(FILE):$(OBJ)
	gcc -o $@ $^

$(BIN)/main.o:main.c
	gcc -o $(BIN)/main.o -c $^


$(BIN)/poker.o:$(SRC)/poker.c $(INC)/poker.h
	gcc -o $(BIN)/poker.o -c $(SRC)/poker.c

clean:
	rm -rf *.out $(BIN)/*
