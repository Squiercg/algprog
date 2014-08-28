#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define n 5

typedef struct {
  int lin;
  int col;
} threadinfo;

int Y[n][n];
int X[n][n];
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
    for(j=0;j<n;j++) {
      pthread_join(thread_matriz[i][j], NULL);
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


