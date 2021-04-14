ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif

FILE=poker.$(EXEC)
BIN=./bin
SRC=./src
INC=./inc
UNITY=./unity
TEST=./test
OBJ=$(BIN)/main.o $(BIN)/poker.o

all: $(FILE)

$(FILE):$(call FixPath,$(OBJ))
	gcc -o $@ $^

$(call FixPath,$(BIN)/main.o):main.c
	gcc -o $(call FixPath,$(BIN)/main.o) -c $^


$(call FixPath,$(BIN)/poker.o):$(call FixPath,$(SRC)/poker.c) $(call FixPath,$(INC)/poker.h)
	gcc -o $(call FixPath,$(BIN)/poker.o) -c $(call FixPath,$(SRC)/poker.c)

test: $(call FixPath,$(BIN)/poker.o)
	gcc $(call FixPath,$(TEST)/tests.c) $(call FixPath,$(SRC)/poker.c) $(call FixPath,$(UNITY)/unity.c)

clean:
	$(RM) *.$(EXEC) $(call FixPath,$(BIN)/*.o)
