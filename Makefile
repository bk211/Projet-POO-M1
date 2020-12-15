CC = g++
CFLAGS = -Wall -std=c++11

test:	test_exec
	./test_exec

test_exec:	Test.o Parseur.o Carte.o Exceptions.o
	$(CC) $(CFLAGS) $^ -o $@

Test.o:	Test.cpp
	$(CC) $(CFLAGS) $< -c

Parseur.o:	Parseur.cpp Parseur.hpp
	$(CC) $(CFLAGS) $< -c

Carte.o:	Carte.cpp Carte.hpp
	$(CC) $(CFLAGS) $< -c

clean:
	rm -rf *.o *.exe test_exec

Exceptions.o: Exceptions.cpp Exceptions.hpp
	$(CC) $(CFLAGS) $< -c