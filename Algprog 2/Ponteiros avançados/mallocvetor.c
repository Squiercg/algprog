#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   int i, n, *vetor, *pt;

   printf("Entre com o tamanho do vetor\n");
   scanf("%d", &n);

   vetor = (int *) malloc(n * sizeof(int));

   if (vetor != NULL) {

     printf("Entre os elementos do vetor\n");
      for (i = 0; i < n; i++)
         scanf("%d", (vetor + i));

      for (pt = vetor; pt < (vetor + n); pt++)
         printf("%d ", *pt);
      printf("\n");

      for (i = n - 1; i >= 0; i--)
         printf("%d ", vetor[i]);
      printf("\n");
   } else {
      printf("Impossível alocar espaço\n");
   }

   return 0;
}
