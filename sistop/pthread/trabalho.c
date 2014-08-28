#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define n 5

typedef struct {
  int lin;
  int col;
} threadinfo;

int matriz[n][n];
pthread_barrier_t bar[n][n];

int max(int a, int b, int c){

  int saida;

  if(a>b && a>c){
    saida = a;
  } else {
    if(b>c) {
      saida = b;
    } else {
      saida = c;
    }
  }

}

void *matriz_paralela(void *dados) {
  threadinfo data = *((threadinfo*)dados);
  int i;


  if(data.lin==0) {
    matriz[data.lin][data.col]=rand()%101;
    pthread_barrier_wait(&bar[data.lin][data.col]);
  } else {
    if(data.col==0 || data.col==(n-1)) {
      if(data.lin==(n-1)) {
	matriz[data.lin][data.col]=matriz[data.lin][data.col];
      } else {
	matriz[data.lin][data.col]=matriz[data.lin][data.col];
	pthread_barrier_wait(&bar[data.lin][data.col]);
      }
    } else {
      if(data.lin==(n-1)) {
	matriz[data.lin][data.col]=max(matriz[data.lin-1][data.col-1],matriz[data.lin-1][data.col],matriz[data.lin-1][data.col+1]);
      } else {
	matriz[data.lin][data.col]=max(matriz[data.lin-1][data.col-1],matriz[data.lin-1][data.col],matriz[data.lin-1][data.col+1]);
	pthread_barrier_wait(&bar[data.lin][data.col-1]);
	pthread_barrier_wait(&bar[data.lin][data.col]);
	pthread_barrier_wait(&bar[data.lin][data.col+1]);
      }
    }
  }

  printf("thread linha: %d coluna %d  acabou\n",data.lin,data.col);

  pthread_exit(NULL);
}

int main(void) {
  pthread_t thread_matriz[n][n];
  int codigo_de_erro, i, j;
  threadinfo info[n][n];

  for(i=0;i<n;i++){
    for(j=0;j<n;j++) {
      info[i][j].lin=i;
      info[i][j].col=j;
    }
  }


  for(i=0;i<n;i++){
    for(j=0;j<n;j++) {

      if(i>0) {
	if(j>=1 || j<=(n-2))
	  pthread_barrier_init(&bar[i][j], NULL, 2);
	else
	  pthread_barrier_init(&bar[i][j], NULL, 3);
      }

      codigo_de_erro = pthread_create(&thread_matriz[i][j], NULL, matriz_paralela , (void*)&info[i][j] );
      if(codigo_de_erro != 0) {
	printf("Erro na criação de thread filha, Codigo de erro %d\n", codigo_de_erro);
	exit(1);
      }
    }
  }


  for(i=0;i<n;i++){
    for(j=0;j<n;j++) {
      pthread_join(thread_matriz[i][j], NULL);
    }
  }

  printf("fechou\n");

  for(i=0;i<n;i++){
    for(j=0;j<n;j++) {
      printf("%03d ",matriz[i][j]);
    }
    printf("\n");
  }

  printf("Acabando a thread main...\n");

  pthread_exit(NULL);
  return 0;
}


