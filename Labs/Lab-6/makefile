# Justin Ventura COSC320
# Lab-6 Makefile (Dr. Anderson)

# makefile variables
gc = g++ -c -std=c++11 # would be c++20 but not allowed :(
go = g++ -o

main: main.o timer.o
	$(go) main main.o timer.o

main.o: main.cpp timer.o heap.cpp heap.h heapq.cpp heapq.h jspace.h jspace.cpp
	$(gc) main.cpp

timer.o: timer.cpp timer.h
	$(gc) timer.cpp

# run make memcheck for memory checking.
memcheck:
	valgrind --leak-check=yes ./main

clean:
	rm *.o main
