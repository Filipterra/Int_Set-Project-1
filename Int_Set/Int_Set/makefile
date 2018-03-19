CC= g++

CFLAGS= -c

all: CFLAGS+= -O3 -Os
all: executable

debug: CFLAGS+= -DDEBUG -g
debug: executable

executable: Int_Set.o Class_Set.o
	$(CC) Int_Set.o Class_Set.o -o IntSet

Int_Set.o: Int_Set.cpp Class_Set.hpp
	$(CC) $(CFLAGS) Int_Set.cpp

Class_Set.o: Class_Set.cpp Class_Set.hpp
	$(CC) $(CFLAGS) Class_Set.cpp

clean:
	rm -f *.o IntSet
