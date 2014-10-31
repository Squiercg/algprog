all: trabalho inicio

inicio: trabalho
	./trabalho -g -u exemplo01.fasta -v exemplo02.fasta -i 1 -d 0 -e -1
trabalho.o: trabalho.cpp Classes.h
	g++ -c trabalho.cpp

Classes.o: Classes.cpp Classes.h
	g++ -c Classes.cpp

trabalho: Classes.o trabalho.o
	g++ trabalho.o Classes.o -o trabalho
