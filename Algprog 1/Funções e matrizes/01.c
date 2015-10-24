#include <stdio.h>

#define MAX 100

/* Recebe dois números inteiros a e b e devolve esses valores trocados */
void troca(int *a, int *b) {
  int aux;
  aux = *a;
  *a = *b;
  *b = aux;
}

/* Recebe uma matriz de dimensão mxn de números inteiros
e os índices i e j de duas linhas da matriz, troca o
conteúdo dessas linhas e mostra a matriz resultante */

int main(void)
{
  int m, n, i, j, k, A[MAX][MAX];

  scanf("%d%d", &m, &n);
  /*Entrada*/
  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
      scanf("%d", &A[i][j]);

  scanf("%d%d", &i, &j);

  /*Processamento*/
  for (k = 0; k < n; k++)
    troca(&A[i][k], &A[j][k]);

  /*Saida*/
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++)
      printf("%d ", A[i][j]);
    printf("\n");
  }
return 0;
}
