.PHONY: all clean pdf rmpdf

all: p1.cpp randomDAG.cpp
	g++ -std=c++11 -O3 -Wall p1.cpp -lm -o p1.out
	g++ -std=c++11 -O3 -Wall randomDAG.cpp -lm -o randomDAG.out

clean: rmpdf
	rm p1.out randomDAG.out report.tex

pdf:
	pdflatex report.tex

rmpdf:
	rm report.pdf
