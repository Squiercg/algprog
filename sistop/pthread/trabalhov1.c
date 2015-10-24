#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*Tamanho da matriz*/
#define n 5

/*Apenas um struct para enviar as informações para a thread*/
typedef struct {
  int lin;
  int col;
} threadinfo;

/*Matrizes de dados*/
int Y[n][n];
int X[n][n];


/*Função que recebe 3 inteiros e retorna o maior*/
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
  return saida;
}

/*Função que faz os calculos necessarios, usada como thread*/
void *matriz_paralela(void *dados) {
  threadinfo data = *((threadinfo*)dados);
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

  /*Alimentando os dados para as threads*/
  for(i=0;i<n;i++){
    for(j=0;j<n;j++) {
      info[i][j].lin=i;
      info[i][j].col=j;
      Y[i][j]=(rand()%10)+1;
    }
  }

  /*Criando as threads, linha por linha*/
  for(i=0;i<n;i++){
    for(j=0;j<n;j++) {
      codigo_de_erro = pthread_create(&thread_matriz[i][j], NULL, matriz_paralela , (void*)&info[i][j] );
      if(codigo_de_erro != 0) {
	printf("Erro na criação de thread filha, Codigo de erro %d\n", codigo_de_erro);
	exit(1);
      }
    }
  /*Apos inicializar toda uma linha de n threads, esperamos todas finalizarem antes de pular para a proxima linha*/
    for(j=0;j<n;j++) {
      pthread_join(thread_matriz[i][j], NULL);
    }
  }

  /*Saida, so deve ser impresso no final*/
  printf("Matriz Y Final: \n");

  for(i=0;i<n;i++){
    for(j=0;j<n;j++) {
      printf("%02d ",Y[i][j]);
    }
    printf("\n");
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


