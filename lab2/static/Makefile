# Makefile for Hotel system

all: main.o libhotel.a libmenu.a
	g++ -o all main.o -L. -lhotel -lmenu

main.o: main.cpp
	g++ -c main.cpp

libhotel.a: hotel.o hotel_functions.o
	ar cr libhotel.a hotel.o hotel_functions.o

libmenu.a: menu.o
	ar cr libmenu.a menu.o

menu.o: menu/menu.cpp
	g++ -c menu/menu.cpp

hotel.o: hotel/hotel.cpp
	g++ -c hotel/hotel.cpp

hotel_functions.o: hotel/hotel_functions.cpp
	g++ -c hotel/hotel_functions.cpp

clean:
	rm -f *.o *.a all