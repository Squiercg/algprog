all: filosofo filosofo_sem_deadlock

filosofo.o: filosofo.c
	gcc -c filosofo.c 

filosofo: filosofo.o
	gcc filosofo.o -lpthread -o filosofo

filosofo_sem_deadlock.o: filosofo_sem_deadlock.c
	gcc -c filosofo_sem_deadlock.c 

filosofo_sem_deadlock: filosofo_sem_deadlock.o
	gcc filosofo_sem_deadlock.o -lpthread -o filosofo_sem_deadlock
