CC=g++
CFLAGS=-c -Wall

all: emparelhamento

emparelhamento: main.o leitor.o processador.o
	g++ main.o leitor.o processador.o -o processador

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

leitor.o: leitor.cpp
	$(CC) $(CFLAGS) leitor.cpp

processador.o: processador.cpp
	$(CC) $(CFLAGS) processador.cpp

clean:
	rm *o emparelhamento
