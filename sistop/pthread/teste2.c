#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define n 5

    pthread_barrier_t bar;
pthread_t thread_exemplo[n];

void *exemplo(void* parametro)
{
    int valor = *((int*)parametro);


    
    printf("Inicio, thread %d\n", valor);

    if(valor>0)
       pthread_join(thread_exemplo[valor-1],NULL);

    printf("Fim, thread %d\n", valor);


if(valor==n-1)
    pthread_barrier_wait(&bar);

    pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
    int i;
    printf("Início da thread main\n");

    pthread_barrier_init(&bar,NULL,2);
    
    int codigo_de_erro, valor[n];


for(i=0;i<n;i++) {
    valor[i] = i;
    codigo_de_erro = pthread_create(&thread_exemplo[i], NULL, exemplo, (void*)&valor[i]);
        if (codigo_de_erro != 0){
        printf("ERRO na criação da thread filha. Código do erro: %d\n", codigo_de_erro);
        exit(1);
    }


}
pthread_barrier_wait(&bar);

    printf("Acabou a thread main\n");

    pthread_exit(NULL);
    return 0;
}