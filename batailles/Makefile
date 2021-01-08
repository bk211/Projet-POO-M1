CC = g++
CFLAGS = -Wall -std=c++11
HEADER = libCardGame.hpp batailles.hpp
LIBOBJ = $(LIBSRC:.cpp=.o)


run:	exec
	./exec

exec:	Main.o Batailles.o libCardGame.a
	$(CC) $(CFLAGS) $^ -o $@

Main.o:	Main.cpp $(HEADER) 
	$(CC) $(CFLAGS) $< -c 

Batailles.o:	Batailles.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c

update_lib: ../libCardGame.a ../libCardGame.hpp
	rm -rf libCardGame.a libCardGame.hpp
	cp $^ .

clean:
	rm -rf *.o *.exe test_exec 