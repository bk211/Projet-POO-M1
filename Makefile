CC = g++
CFLAGS = -Wall -std=c++11

test:	test.o
	./test.o

test.o:	Parseur.o Test.o
	$(CC) $(CFLAGS) $^ -o $@

Test.o:	Test.cpp
	$(CC) $(CFLAGS) $< -c

Parseur.o:	Parseur.cpp Parseur.hpp
	$(CC) $(CFLAGS) $< -c
