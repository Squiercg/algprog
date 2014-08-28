#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define n 5

int Y[n][n];
int X[n][n];
pthread_barrier_t bar[n][n];

typedef struct {
  int lin;
  int col;
  int quantidade;
  pthread_barrier_t thread_esperar[n];
} threadinfo;

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

  for(i=0;i<data.quantidade;i++) {
    pthread_join(data.thread_esperar[i], NULL);
  }

  if(data.lin==0) {
    X[data.lin][data.col]=(rand()%100)+1;
  } else {
    if(data.col==0 || data.col==(n-1)) {
      X[data.lin][data.col]=X[data.lin-1][data.col]+Y[data.lin][data.col];
    } else {
      X[data.lin][data.col]=max(X[data.lin-1][data.col-1],
				X[data.lin-1][data.col],
				X[data.lin-1][data.col+1])+Y[data.lin][data.col];
    }
  }
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
      Y[i][j]=(rand()%10)+1;
      if(i>0 && (j==0 || j==(n-1))) {
	info[i][j].quantidade=1;
	pthread_barrier_init(&bar[i-1][j],NULL,1);
	info[i][j].thread_esperar[0]=bar[i-1][j];
      }
    }
  }


  for(i=0;i<n;i++){
    for(j=0;j<n;j++) {
      codigo_de_erro = pthread_create(&thread_matriz[i][j], NULL, matriz_paralela , (void*)&info[i][j] );
      if(codigo_de_erro != 0) {
	printf("Erro na criação de thread filha, Codigo de erro %d\n", codigo_de_erro);
	exit(1);
      }
    }
  }


  printf("Matriz X Final: \n");

  for(i=0;i<n;i++){
    for(j=0;j<n;j++) {
      printf("%03d ",X[i][j]);
    }
    printf("\n");
  }

  pthread_exit(NULL);
  return 0;
}


