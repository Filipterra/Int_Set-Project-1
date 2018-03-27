CC= g++

CFLAGS= -c -std=c++11

all: CFLAGS+= -O3 -Os
all: executable

debug: CFLAGS+= -D_DEBUG -g
debug: executable

executable: Int_Set.o Class_Set.o Test.o GUI.o
	$(CC)  Int_Set.o Class_Set.o Test.o GUI.o -o Int_Set

Int_Set.o: Int_Set.cpp Class_Set.hpp
	$(CC) $(CFLAGS) Int_Set.cpp

Class_Set.o: Class_Set.cpp Class_Set.hpp
	$(CC) $(CFLAGS) Class_Set.cpp

Test.o: Test.cpp Test.hpp Class_Set.hpp
	$(CC) $(CFLAGS) Test.cpp

GUI.o: GUI.cpp GUI.hpp Class_Set.hpp
	$(CC) $(CFLAGS) GUI.cpp

clean:
	rm -f *.o Int_Set
