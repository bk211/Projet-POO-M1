CC = g++
CFLAGS = -Wall -std=c++11
HEADER = libCardGame.hpp Uno.hpp
BINAIRES = Uno.o UnoCard.o UnoGameModel.o UnoGameView.o JouerCommand.o PiocherCommand.o UnoCommand.o

run:	exec
	./exec

exec:	Main.o $(BINAIRES) libCardGame.a
	$(CC) $(CFLAGS) $^ -o $@

Main.o:	Main.cpp $(HEADER) 
	$(CC) $(CFLAGS) $< -c 

Uno.o:	Uno.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c

UnoCard.o:	UnoCard.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c

UnoGameModel.o:	UnoGameModel.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c

UnoGameView.o:	UnoGameView.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c

JouerCommand.o:	JouerCommand.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c

PiocherCommand.o:	PiocherCommand.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c

UnoCommand.o:	UnoCommand.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c

Test.o:	Test.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c

test:	test_exec
	./test_exec

test_exec:	Test.o $(BINAIRES) libCardGame.a
	$(CC) $(CFLAGS) $^ -o $@


update_lib: ../libCardGame.a ../libCardGame.hpp
	rm -rf libCardGame.a libCardGame.hpp
	cp $^ .


clean:
	rm -rf *.o *.exe test_exec 
