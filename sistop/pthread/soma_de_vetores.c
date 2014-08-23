#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define n 10

/*
volatile int running_threads = 0;
*/

int A[n], B[n], C[n];

void *soma_de_vetores(void *id_thread) {
  int id = *((int*)id_thread);

  printf("Thread %d operando\n",id);
  C[id]=A[id]+B[id];
  /*running_threads--;*/
  pthread_exit(NULL);

}

int main(void) {
  int i, vetor[n];
  pthread_t thread_soma[n];
  int codigo_de_erro;


  for(i=0;i<n;i++){
    A[i]=9;
    B[i]=1;
  }

  for(i=0;i<n;i++){
    /*Pulo do gato, como mandar a informação*/
    vetor[i]=i;
    codigo_de_erro = pthread_create(&thread_soma[i], NULL, soma_de_vetores , (void*)&vetor[i] );
    if(codigo_de_erro != 0) {
      printf("Erro na criação de thread filha, Codigo de erro %d\n", codigo_de_erro);
      exit(1);
    }
    /*pthread_join(thread_soma[i], NULL); Versao Errada*/
    /*running_threads++;*/
  }

  /*
  while (running_threads > 0) {
    sleep(1);
  }
  */

  for (i = 0; i < n; i++) {
    pthread_join(thread_soma[i], NULL);
  }

  for(i=0;i<n;i++){
    printf("C[%d]=%d\n",i,C[i]);
  }

  printf("Acabando a thread main...\n");

  pthread_exit(NULL);
  return 0;

}
