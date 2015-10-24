all: trabalho inicio

inicio: trabalho
	./trabalho	

trabalho.o: trabalho.cpp Classes.h
	g++ -c trabalho.cpp

Classes.o: Classes.cpp Classes.h
	g++ -c Classes.cpp

trabalho: Classes.o trabalho.o
	g++ trabalho.o Classes.o -o trabalho
