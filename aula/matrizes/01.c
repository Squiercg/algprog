#include <stdio.h>

/* Dadas duas matrizes de números inteiros A e B, de dimensões m×n,
com 1 <=m,n <=100, fazer um programa que calcule a matriz Cm×n = A + B.*/

#define MAX 100

int main(void)
{

  int m, n, i, j,A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

  /*Entrada de dados*/
  printf("Informe as dimensões (m,n) das matrizes: ");
  scanf("%d%d", &m, &n);
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      printf("Informe A[%2d][%2d]: ", i, j);
      scanf("%d", &A[i][j]);
    }
  }



  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      printf("Informe B[%2d][%2d]: ", i, j);
      scanf("%d", &B[i][j]);
    }
  }

  /*Processamento de dados*/

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      C[i][j] = A[i][j] + B[i][j];
    }
  }

  /*Saida de dados*/
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++){
      printf("%2d ", C[i][j]);
    }
      printf("\n");
  }


  return 0;
}
