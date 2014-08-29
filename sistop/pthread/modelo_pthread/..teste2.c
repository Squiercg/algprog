#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int j;
pthread_barrier_t bar;

void *exemplo(void* parametro)
{
    int valor = *((int*)parametro);
    printf("Olá, eu sou a thread exemplo e recebi o parametro %d\n", valor);
    printf("j: %d", j);

    pthread_barrier_wait(&bar);
    pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
    printf("j: %d", j);
    printf("Início da thread main\n");

    pthread_barrier_init(&bar, NULL, 2);
    
    pthread_t thread_exemplo;
    int codigo_de_erro, valor = 20;

    codigo_de_erro = pthread_create(&thread_exemplo, NULL, exemplo, (void*)&valor);
    
    if (codigo_de_erro != 0){
        printf("ERRO na criação da thread filha. Código do erro: %d\n", codigo_de_erro);
        exit(1);
    }

    pthread_barrier_wait(&bar);
    
    printf("Acabou a thread main\n");

    pthread_exit(NULL);
    return 0;
}