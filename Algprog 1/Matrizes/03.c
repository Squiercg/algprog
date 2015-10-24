#include <stdio.h>

/*Dada uma matriz de números reais A com m linhas e n colunas, 1<=m,n<=100,
  e um vetor de números reais v com n elementos, determinar o produto de A por v.*/

#define MAX 100

int main(void)
{

  int m, n , i, j, matriz[MAX][MAX], vetor[MAX],produto[MAX] = {0};

  /*Entrada de dados*/
  printf("Informe as dimensões (m,n) da matriz: ");
  scanf("%d%d", &m, &n);
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      printf("Informe Matriz[%2d][%2d]: ", i, j);
      scanf("%d", &matriz[i][j]);
    }
  }

  printf("Informe o vetor: \n");

  for (j = 0; j < n; j++) {
      printf("Informe Vetor[%2d]: ", j);
      scanf("%d", &vetor[j]);
  }


  /*Processamento de dados*/

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      produto[i] = (matriz[i][j]*vetor[j]) + produto[i];
    }
  }

  /*Saida de dados*/

  for (i = 0; i < m; i++) {
    printf("%d ", produto[i]);
  }
  printf("\n");

  return 0;
}
