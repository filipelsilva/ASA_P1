.PHONY: all clean

all: p1.cpp
	g++ -std=c++11 -O3 -Wall p1.cpp -lm -o p1.out

clean: p1.out
	rm p1.out
