#include <stdio.h>
/* Esse programa pega um número e testa se ele é primo */

int main(void)
{
  int num , soma , passo;

  printf("Digite um número inteiro positivo: ");
  scanf("%d",&num);

  passo = 2;
  soma = 0;

  while (passo < num) {
    if (num % passo != 0) {
      soma = soma + 1;
    }
      passo = passo + 1;
    }

  if(soma == num-2)
    printf("O numero %d é primo.\n",num);
  else
    printf("O número %d não é primo.\n",num);

      return 0;

}
