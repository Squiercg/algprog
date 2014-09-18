/*
Augusto Ribas
Thiago Machado
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define n 5

/*Uma barreira para segurar as threads*/
pthread_barrier_t bar[n][n];
/*Uma Matriz de idenficação de threads*/
pthread_t thread_matriz[n][n];


/*Apenas um struct para enviar as informações para a thread*/
typedef struct {
  int lin;
  int col;
} threadinfo;

/*Matrizes de dados*/
int Y[n][n];
int X[n][n];

/*Uma função que recebe 3 inteiros e retorna o maior entre eles*/
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


/*Função que faz os calculos da thread*/
void *matriz_paralela(void *dados) {
  threadinfo data = *((threadinfo*)dados);

  /*printf("Inicio %d %d\n",data.lin,data.col);*/

  /*Troquei basicamente a mesma estratégia que tava tentando implementar com o join para barreiras, a diferença é que
   * precisamos ter um start na barreira na thread de quem calcula o valor, um de quem depende. So que desse jeito so
   * da certo para quando o n é maior que 3, porque se não tiver meio da matriz pra calcular, acho que vai falhar, mas
   * acredito que tudo ta funcionando agora, os printfs são apenas para acompanhar os threads*/


  /*Aqui temos o processamento dos dados, conforme o exercicio pede*/
  if(data.lin==0) {
    X[data.lin][data.col]=(rand()%100)+1;
    pthread_barrier_wait(&bar[data.lin][data.col]);
  } else {
    if(data.col==0 || data.col==(n-1)) {
      pthread_barrier_wait(&bar[data.lin-1][data.col]);

      X[data.lin][data.col]=X[data.lin-1][data.col]+Y[data.lin][data.col];
      if(data.lin<(n-1))
	pthread_barrier_wait(&bar[data.lin][data.col]);

    } else {
      pthread_barrier_wait(&bar[data.lin-1][data.col-1]);
      pthread_barrier_wait(&bar[data.lin-1][data.col]);
      pthread_barrier_wait(&bar[data.lin-1][data.col+1]);

      X[data.lin][data.col]=max(X[data.lin-1][data.col-1],
				X[data.lin-1][data.col],
				X[data.lin-1][data.col+1])+Y[data.lin][data.col];
      if(data.lin<(n-1))
	pthread_barrier_wait(&bar[data.lin][data.col]);
    }
  }

  /*printf("Fim %d %d\n",data.lin,data.col);*/

  /*Mudando o status da thead antes de mata-la, para nao correr o risco de tentar dar join um uma thread que ja morreu*/
  pthread_exit(NULL);
}

int main(void) {
  int codigo_de_erro, i, j;
  threadinfo info[n][n];


  /*Alimentando os dados para as threads*/
  for(i=0;i<n;i++){
    for(j=0;j<n;j++) {
      info[i][j].lin=i;
      info[i][j].col=j;
      Y[i][j]=(rand()%10)+1;

      /*Iniciando as barreiras, não precisamos de barreira na ultima linha*/
      if(i<(n-1)) {
	if(j<=1 || j>=(n-2)) {
	  pthread_barrier_init(&bar[i][j],NULL,3);
	} else {
	  pthread_barrier_init(&bar[i][j],NULL,4);
	}
      }
    }
  }

  /*Criando todas as threads*/
  for(i=0;i<n;i++){
    for(j=0;j<n;j++) {
      codigo_de_erro = pthread_create(&thread_matriz[i][j], NULL, matriz_paralela , (void*)&info[i][j] );
      if(codigo_de_erro != 0) {
	printf("Erro na criação de thread filha, Codigo de erro %d\n", codigo_de_erro);
	exit(1);
      }
    }
  }

  /*Sincronização, para esperar todo o processamento para imprimir o resultado*/
  for(i=0;i<n;i++){
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


