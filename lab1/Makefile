# Makefile for Hotel system

SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.cpp=.o)


program: $(OBJS)
	g++ -o program $^


%.o: %.cpp
	g++ -c $<


clean: 
	rm -f *.o program