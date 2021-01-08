CC = g++
CFLAGS = -Wall -std=c++11
HEADER = libCardGame.hpp batailles.hpp
LIBOBJ = $(LIBSRC:.cpp=.o)


run:	exec
	./exec

exec:	Main.o libCardGame.a Batailles.o $(HEADER)
	$(CC) $(CFLAGS) $^ -o $@

Main.o:	Main.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

Batailles.o:	Batailles.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

update_lib: ../libCardGame.a ../libCardGame.hpp
	cp $^ .

clean:
	rm -rf *.o *.exe test_exec lib/*.o lib/*.exe
