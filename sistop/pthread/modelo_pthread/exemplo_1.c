#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *exemplo(void* parametro)
{
	if(parametro == NULL)
		printf("Eu estaria aqui!!!");
	while(1) {
		printf("Olá, eu sou a thread exemplo!\n");
	}

	pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
	printf("Início da thread main\n");
	
	pthread_t thread_exemplo;
	int codigo_de_erro;

	codigo_de_erro = pthread_create(&thread_exemplo, NULL, exemplo, NULL);
	
	if (codigo_de_erro != 0){
		printf("ERRO na criação da thread filha. Código do erro: %d\n", codigo_de_erro);
		exit(1);
	}
	
	while(1) {
		printf("Olá eu sou a thread main\n");
	}

	pthread_exit(NULL);
	return 0;
}