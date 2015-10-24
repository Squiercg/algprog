/*
    Augusto Ribas    
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define n 5

pthread_mutex_t chave_vetor;
pthread_cond_t condc, condp;
int vetor[n];
int quantidade, prod, cons;



void* produtor(void *arg) {

  while(1) {
    printf("Produtor: antes do lock\n");
    pthread_mutex_lock(&chave_vetor);	/* Protege o vetor */
    printf("Produtor: depois do lock\n");

    while (quantidade >= n) {		       /* Se o vetor ta cheio, esperamos */
      printf("Produtor dormiu\n");
      pthread_cond_wait(&condp, &chave_vetor);
    }


    vetor[prod]=rand()%10+1;
    printf("Produzido: Vetor[%d]=%d\n",prod,vetor[prod]); 
    prod=(prod+1)%n;
    quantidade++;    
    printf("Quantidade = %d\n",quantidade);
    pthread_cond_signal(&condc);  /* Acorda o consumidor */
    pthread_mutex_unlock(&chave_vetor); /* Libera o vetor */
    printf("Produtor: saiu do lock\n");
    sleep(rand()%3); 
    //sleep(1);
  }
  pthread_exit(NULL);
}

void* consumidor(void *arg) {

  while(1) {
    printf("Consumidor: antes do lock\n");
    pthread_mutex_lock(&chave_vetor);	/* Protege o vetor */
    printf("Consumidor: depois do lock\n");
    while (quantidade <= 0) {			/* Se o vetor ta vaziu, esperamos */
      printf("Consumidor dormiu\n");
      pthread_cond_wait(&condc, &chave_vetor);
    }

    printf("Consumido: Vetor[%d]=%d\n",cons,vetor[cons]);
    cons=(cons+1)%n;
    quantidade--;
    printf("Quantidade = %d\n",quantidade);

    pthread_cond_signal(&condp);  /* Acorda o produtor */
    pthread_mutex_unlock(&chave_vetor); /* Libera o vetor */
    printf("Consumidor: saiu do lock\n");
    sleep(rand()%3);
    //sleep(1);
  }
  pthread_exit(NULL);
}

int main(int argc, char **argv) {
  pthread_t pro, con;
  int codigo_de_erro;

  quantidade=0;
  prod=0;
  cons=0;

  /*Inicia a chave do vetor e as variaveis de condição */
  pthread_mutex_init(&chave_vetor, NULL);	
  pthread_cond_init(&condc, NULL);		/* Inicializa a variavel de condição do consumidor*/
  pthread_cond_init(&condp, NULL);		/* Inicializa a variavel de condição do produtor */

  // Cria as threads
  codigo_de_erro = pthread_create(&con, NULL, consumidor, NULL);
  if(codigo_de_erro != 0) {
    printf("Erro na criação de thread filha, Codigo de erro %d\n", codigo_de_erro);
    exit(1);
  }

  codigo_de_erro = pthread_create(&pro, NULL, produtor, NULL);
  if(codigo_de_erro != 0) {
    printf("Erro na criação de thread filha, Codigo de erro %d\n", codigo_de_erro);
    exit(1);
  }

  // Esperamos as threads (Que nunca vão acabar, para continuar a main)
  pthread_join(con, NULL);
  pthread_join(pro, NULL);

  // Limpamos tudo
  pthread_mutex_destroy(&chave_vetor);	/**/
  pthread_cond_destroy(&condc);		/**/
  pthread_cond_destroy(&condp);		/**/

  return 0;
}