CC = g++
CFLAGS = -Wall -std=c++11
HEADER = libCardGame.hpp Huit.hpp
BINAIRES = Huit.o HuitCard.o HuitGameModel.o HuitGameView.o JouerCommand.o PiocherCommand.o HuitCommand.o IAJouerCommand.o 

run:	exec
	./exec

exec:	Main.o $(BINAIRES) libCardGame.a
	$(CC) $(CFLAGS) $^ -o $@

Main.o:	Main.cpp $(HEADER) 
	$(CC) $(CFLAGS) $< -c 

Huit.o:	Huit.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c

HuitCard.o:	HuitCard.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c

HuitGameModel.o:	HuitGameModel.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c

HuitGameView.o:	HuitGameView.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c

JouerCommand.o:	JouerCommand.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c

PiocherCommand.o:	PiocherCommand.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c

HuitCommand.o:	HuitCommand.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c

IAJouerCommand.o:	IAJouerCommand.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c


update_lib: ../libCardGame.a ../libCardGame.hpp
	rm -rf libCardGame.a libCardGame.hpp
	cp $^ .


clean:
	rm -rf *.o *.exe test_exec 
