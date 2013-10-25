#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int i, n;
  char *cadeia;

   printf("Entre com o tamanho do vetores\n");
   scanf("%d", &n);

   cadeia = (char *) malloc((n+1) * sizeof(char));


   if (cadeia != NULL) {

     scanf("\n%[^\n]",cadeia);


  } else {
      printf("Impossível alocar espaço\n");
   }

   return 0;
}
