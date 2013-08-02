#include <stdio.h>

/* Fazer um programa que dada uma matriz de números reais A m×n , determine A^t .
   Suponha que 1<= m,n<= 100.*/

#define MAX 100

int main(void)
{

  int m, n, i, j,A[MAX][MAX],At[MAX][MAX];

  /*Entrada de dados*/
  printf("Informe as dimensões (m,n) das matrizes: ");
  scanf("%d%d", &m, &n);
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      printf("Informe A[%2d][%2d]: ", i, j);
      scanf("%d", &A[i][j]);
    }
  }

  /*Processamento de dados*/

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      At[j][i] = A[i][j];
    }
  }

  /*Saida de dados*/
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++){
      printf("%2d ", At[i][j]);
    }
      printf("\n");
  }


  return 0;
}
