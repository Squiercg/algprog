#include <stdio.h>

/* Recebe um inteiro e imprime a quantidade de dígitos que possui */

int main(void)
{
  int n, digitos;
  printf("Informe n: ");
  scanf("%d", n);


  do {
    n = n / 10;
    digitos++;
  } while (n > 0);


  printf("O número tem %d dígitos\n", digitos);
  return 0;
}
