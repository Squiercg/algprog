#include <stdio.h>

/* Esse programa avalia a função p(x) = 3x³ − 5x² + 2x − 1. */

int main(void)
{

  int n , resultado;

  printf("Entre com valor de n: ");
  scanf("%d", &n);

  resultado = 3*(n*n*n) -5*(n*n) +2*(n) -1;

  printf("O resultado da expressão para %d é %d.\n",n,resultado);

  return 0;

}
