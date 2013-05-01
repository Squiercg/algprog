#include <stdio.h>

int main(void)
{
  int numero;

  printf("Digite um número: ");
  scanf("%d", &numero);
  if (numero == 0)
    printf("Não se aplica ao número %d.\n",numero);
  else {
    if (numero % 2 == 0)
      printf("O número %d é par.\n",numero);
    else
      printf("O número %d é impar.\n",numero);
  }
 
  return 0;
}
