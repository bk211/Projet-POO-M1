CC = g++
CFLAGS = -Wall -std=c++11
HEADER = libCardGame.hpp Briscola.hpp
BINAIRES = Briscola.o BriscolaGameView.o JouerCommand.o


run:	exec
	./exec

exec:	Main.o $(BINAIRES) libCardGame.a
	$(CC) $(CFLAGS) $^ -o $@

Main.o:	Main.cpp $(HEADER) 
	$(CC) $(CFLAGS) $< -c 

Briscola.o:	Briscola.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c

BriscolaGameView.o:	BriscolaGameView.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c

JouerCommand.o:	JouerCommand.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c	

update_lib: ../libCardGame.a ../libCardGame.hpp
	rm -rf libCardGame.a libCardGame.hpp
	cp $^ .

clean:
	rm -rf *.o *.exe test_exec 
