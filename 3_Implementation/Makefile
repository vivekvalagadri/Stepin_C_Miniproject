FILE=poker.out

all: $(FILE)

$(FILE):main.c ./src/poker.c
	gcc -o $@ $^

clean:
	rm -rf *.out 
