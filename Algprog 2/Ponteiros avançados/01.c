#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int i, n, *x , *y , saida=0;

   printf("Entre com o tamanho do vetores\n");
   scanf("%d", &n);

   x = (int *) malloc(n * sizeof(int));
   y = (int *) malloc(n * sizeof(int));

   if (x != NULL) {

     printf("Entre os elementos do vetor x\n");
      for (i = 0; i < n; i++)
         scanf("%d", (x + i));

     printf("Entre os elementos do vetor x\n");
      for (i = 0; i < n; i++)
         scanf("%d", (y + i));

      for (i = 0; i < n; i++)
	saida+=x[i]*y[i];
 
      printf("Produto interno: %d ", saida);

  } else {
      printf("Impossível alocar espaço\n");
   }

   return 0;
}
