# Justin Ventura COSC320
# Lab-6 Makefile (Dr. Anderson)

# makefile variables
gc = g++ -c -std=c++11 # would be c++20 but not allowed :(
go = g++ -o

# main
main: main.o
	$(go) main main.o

main.o: main.cpp jspace.h jspace.cpp
	$(gc) main.cpp

clean:
	rm -rf *.o main