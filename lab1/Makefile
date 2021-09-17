# Makefile for Hotel system

program: hotel.o hotel.h.gch main.o
	g++ -o program hotel.o main.o


hotel.h.gch: hotel.h
	g++ -c hotel.h


hotel.o: hotel.cpp
	g++ -c hotel.cpp


main.o: main.cpp
	g++ -c main.cpp


clean: 
	rm -f *.o *.gch program