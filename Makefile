.PHONY: all clean test

all: p1.cpp randomDAG.cpp report.tex
	g++ -std=c++11 -O3 -Wall p1.cpp -lm -o p1.out
	g++ -std=c++11 -O3 -Wall randomDAG.cpp -lm -o randomDAG.out
	pdflatex report.tex

clean: p1.out randomDAG.out report.pdf
	rm p1.out randomDAG.out report.pdf *.aux *.log

test: p1.out
	./p1.out < test.txt
