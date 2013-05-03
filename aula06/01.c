#include <stdio.h>

/* Mostra os 100 primeiros números inteiros positivos */

int main(void)

{

  int numero;
  numero = 1;

  while (numero <= 100) {
    printf("%d ", numero);
    numero = numero + 1;
  }

  printf("\n");
  return 0;
}
