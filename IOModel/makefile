# Justin Ventura COSC320
# Project 1 Makefile 
# IOModel (Dr. Anderson)

# ========== INSTRUCTIONS FOR IOMODEL ===========
#                                               |
#               --- MAKE ALL ---                |
#                                               |
# Run: 'make all' to create each executable if  |
# you wish to manually valgrind each one.       |
#                                               |
#                --- driver ---                 |
#                                               |
# Command to build demo: 'make driver'          |
# Command to run driver: './driver'             |
# Memory check driver: 'make m_driver'          |
#                                               |
#                --- IOModel ---                |
#                                               |
# Command to build IOModel: 'make iomodel'.     |
# Command to run IOmodel: './iomodel <filename>'|
# Memory check IOModel: valgrind --leak-check   |
#      (runs with 'data.txt' by default)        |
#                                               |
#                 --- Clean ---                 |
#                                               |
# Command to clean: 'make clean'                |
#                                               |
# ===============================================

# Makefile variables.
gc = g++ -c -std=c++11
go = g++ -o
binaries = iomodel driver

all: clean iomodel driver

iomodel: iomodel.o matrix.o
	$(go) iomodel iomodel.o matrix.o

iomodel.o: iomodel.cpp matrix.cpp jspace.h jspace.cpp
	$(gc) iomodel.cpp

# Creates executable for driver test.
driver: driver.o matrix.o
	$(go) driver matrix.o driver.o timer.o

# Creates driver object file.
driver.o: driver.cpp matrix.o jspace.h jspace.cpp timer.o
	$(gc) driver.cpp

# Creates matrix object file.
matrix.o: matrix.h matrix.cpp
	$(gc) matrix.cpp

# Creates timer object file.
timer.o: timer.h timer.cpp
	$(gc) timer.cpp

# Memory checking for driver.
m_driver:
	valgrind --leak-check=yes --track-origins=yes ./driver

	# Memory checking for driver.
m_iomodel:
	valgrind --leak-check=yes --track-origins=yes ./iomodel data.txt

# Clean object files and executables.
clean:
	rm -f *.o $(binaries)
