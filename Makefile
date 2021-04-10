.PHONY: all clean test

all: p1.cpp randomDAG.cpp
	g++ -std=c++11 -O3 -Wall p1.cpp -lm -o p1.out
	g++ -std=c++11 -O3 -Wall randomDAG.cpp -lm -o randomDAG.out

clean: p1.out randomDAG.out
	rm *.out

test: p1.out
	./p1.out < test.txt
