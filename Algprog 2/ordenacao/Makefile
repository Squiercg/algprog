principal: principal.o ordena.o
	gcc -o principal principal.o ordena.o -lm
principal.o: principal.c ordena.h
	gcc -c principal.c -lm
ordena.o: ordena.c ordena.h
	gcc -c ordena.c -lm

