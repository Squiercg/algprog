#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *exemplo(void* parametro)
{
	int valor = *((int*)parametro);
	printf("Olá, eu sou a thread exemplo e recebi o parametro %d\n", valor);

	pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
	printf("Início da thread main\n");
	
	pthread_t thread_exemplo;
	int codigo_de_erro, valor = 20;

	codigo_de_erro = pthread_create(&thread_exemplo, NULL, exemplo, (void*)&valor);
	
	if (codigo_de_erro != 0){
		printf("ERRO na criação da thread filha. Código do erro: %d\n", codigo_de_erro);
		exit(1);
	}
	
	printf("Acabou a thread main\n");

	pthread_exit(NULL);
	return 0;
}