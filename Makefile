CC = g++
CFLAGS = -Wall -std=c++11
LIBDIR = lib/
LIBSRC = Carte.cpp Parseur.cpp Exceptions.cpp CollectionCarte.cpp Player.cpp GameModel.cpp Command.cpp
HEADER = libCardGame.hpp

library: libCardGame.a

libCardGame.a: lib/Carte.o lib/Parseur.o lib/Exceptions.o lib/Player.o lib/CollectionCarte.o lib/GameModel.o lib/PlayerManager.o lib/GameController.o lib/GameView.o lib/Command.o
	ar rvs $@ $^

lib/Carte.o:	lib/Carte.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

lib/Parseur.o:	lib/Parseur.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@
	
lib/Exceptions.o:	lib/Exceptions.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

lib/Player.o:	lib/Player.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

lib/CollectionCarte.o:	lib/CollectionCarte.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

lib/GameModel.o:	lib/GameModel.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

lib/PlayerManager.o:	lib/PlayerManager.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

lib/GameView.o:	lib/GameView.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

lib/GameController.o:	lib/GameController.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

lib/Command.o:	lib/Command.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@


migrate: libCardGame.a libCardGame.hpp
	cp $^ batailles/
	cp $^ Briscola/
	cp $^ Uno/
	cp $^ 8Americain/
	
clean:
	rm -rf *.o *.exe test_exec lib/*.o lib/*.exe
