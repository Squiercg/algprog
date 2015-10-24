all: augusto inicio

inicio: augusto
	./augusto < entrada01.txt

augusto.o: augusto.cpp
	g++ -c augusto.cpp

augusto: augusto.o
	g++ augusto.o -o augusto