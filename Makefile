CC = g++
CFLAGS = -Wall -std=c++11
LIBDIR = lib/
LIBSRC = Carte.cpp Parseur.cpp Exceptions.cpp CollectionCarte.cpp Player.cpp GameModel.cpp
HEADER = libCardGame.hpp
LIBOBJ = $(LIBSRC:.cpp=.o)


test:	test_exec
	./test_exec

test_exec:	Test.o libCardGame.a
	$(CC) $(CFLAGS) $^ -o $@

Test.o:	Test.cpp
	$(CC) $(CFLAGS) $< -c

libCardGame.a: lib/Carte.o lib/Parseur.o lib/Exceptions.o lib/Player.o
	ar rvs $@ $^

lib/Carte.o:	lib/Carte.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

lib/Parseur.o:	lib/Parseur.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@
	
lib/Exceptions.o:	lib/Exceptions.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

lib/Player.o:	lib/Player.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@


clean:
	rm -rf *.o *.exe test_exec lib/*.o lib/*.exe
