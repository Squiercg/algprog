#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   int i, j, m, n, **matriz, **pt;

   printf("Entre com o número de linhas e colunas:"
   scanf("%d%d", &m, &n);

   matriz = (int **) malloc(m * sizeof(int *));

   if (matriz == NULL)
      return 0;


   for (pt = matriz, i = 0; i < m; i++, pt++) {
      *pt = (int *) malloc(n * sizeof(int));
      if (*pt == NULL)
	return 0; }

   for (i = 0; i < m; i++)
      for (j = 0; j < n; j++)
	matriz[i][j]=rand()%100;

   pt = matriz;

   for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++)
         printf("%2d ", *(*(pt+i)+j));
      printf("\n"); }

   return 0;
}
