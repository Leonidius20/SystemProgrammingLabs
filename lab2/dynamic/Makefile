# Makefile for Hotel system with dynamic libraries

all: main.o libhotel.so libmenu.so
	g++ -o binary main.o -L. -lhotel -lmenu -Wl,--rpath -Wl,.

main.o: main.cpp
	g++ -c main.cpp

libhotel.so: hotel.o hotel_functions.o
	g++ -shared -o libhotel.so hotel.o hotel_functions.o

libmenu.so: menu.o
	g++ -shared -o libmenu.so menu.o

menu.o: menu/menu.cpp
	g++ -c -fPIC menu/menu.cpp

hotel.o: hotel/hotel.cpp
	g++ -c -fPIC hotel/hotel.cpp

hotel_functions.o: hotel/hotel_functions.cpp
	g++ -c -fPIC hotel/hotel_functions.cpp

clean:
	rm -f *.o *.so binary
