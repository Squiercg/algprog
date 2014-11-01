#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define N 5

pthread_mutex_t garfo[N];
int pratadas;

void* filosofo(void *arg) {
  int i;


  i=*((int*)arg);


  while(1) {


    printf("Filosofo %d pensando!!!\n",i);
    sleep(rand()%3);

    pthread_mutex_lock(&garfo[i]); 
    pthread_mutex_lock(&garfo[(i+(N-1))%N]); 

    printf("Filosofo %d comendo com garfos %d e %d!!!\n",i,i,(i+(N-1))%N);
    pratadas++;
    printf("Ja foram %d pratadas de macarrão.\n\n",pratadas);
    sleep(rand()%3);

    pthread_mutex_unlock(&garfo[i]); 
    pthread_mutex_unlock(&garfo[(i+(N-1))%N]); 
    
  }

  pthread_exit(NULL);
}



int main(int argc, char **argv) {
  pthread_t filosofos[N];
  int codigo_de_erro, i, id[N];

  pratadas=0;

  
  
  for(i=0;i<N;i++) {
    pthread_mutex_init(&garfo[i], NULL);	
    id[i]=i;
  }

  for(i=0;i<N;i++) {
    // Cria as threads
    codigo_de_erro = pthread_create(&filosofos[i], NULL, filosofo, (void*)&id[i]);
    if(codigo_de_erro != 0) {
      printf("Erro na criação de thread filha, Codigo de erro %d\n", codigo_de_erro);
      exit(1);
    }
  }
  
  for(i=0;i<N;i++) {
    pthread_join(filosofos[i], NULL);
  }

  return 0;
}