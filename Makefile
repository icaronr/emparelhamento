CC=g++
CFLAGS=-c -std=c++11 -Wall

all: emparelhamento

emparelhamento: main.o leitor.o processador.o tipos.o
	g++ main.o leitor.o processador.o tipos.o -o processador

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

leitor.o: leitor.cpp
	$(CC) $(CFLAGS) leitor.cpp

processador.o: processador.cpp
	$(CC) $(CFLAGS) processador.cpp

tipos.o: tipos.cpp
	$(CC) $(CFLAGS) tipos.cpp

clean:
	rm *o emparelhamento
