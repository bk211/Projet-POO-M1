CC = g++
CFLAGS = -Wall -std=c++11
HEADER = libCardGame.hpp Uno.hpp

run:	exec
	./exec

exec:	Main.o Uno.o UnoCard.o UnoGameModel.o libCardGame.a
	$(CC) $(CFLAGS) $^ -o $@

Main.o:	Main.cpp $(HEADER) 
	$(CC) $(CFLAGS) $< -c 

Uno.o:	Uno.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c

UnoCard.o:	UnoCard.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c

UnoGameModel.o:	UnoGameModel.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c

update_lib: ../libCardGame.a ../libCardGame.hpp
	rm -rf libCardGame.a libCardGame.hpp
	cp $^ .

clean:
	rm -rf *.o *.exe test_exec 
