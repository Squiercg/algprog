#include <stdio.h>
/*Aluno: Augusto Cesar de Aquino Ribas
Algoritmos de programação turma 03
Analise de sistemas.*/

/* Esse programa recebe duas matrizes e compara se a segunda é o inverso da primeira*/


#define MAX 100

int main(void)
{
  int m, n, i, j, A[MAX][MAX], B[MAX][MAX], At[MAX][MAX],igual=0;

  /*Entrada de dados*/
  printf("Informe as dimensões (n,m) das matrizes: ");
  scanf("%d%d", &n, &m);

  printf("A matriz A: \n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("Informe A[%2d][%2d]: ", i, j);
      scanf("%d", &A[i][j]);
    }
  }

  printf("A matriz B: \n");
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      printf("Informe B[%2d][%2d]: ", i, j);
      scanf("%d", &B[i][j]);
    }
  }

  /*Processamento de dados*/

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      At[j][i] = A[i][j];
    }
  }

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      if(At[i][j]!=B[i][j])
	igual=1;
    }
  }


  /*Saida de dados*/
  if(igual==1)
    printf("Não são iguais\n");
  else
    printf("São iguais\n");

  return 0;
}
