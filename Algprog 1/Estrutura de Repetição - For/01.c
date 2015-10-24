#include <stdio.h>

/* Imprime os números inteiros positivos de 4 dígitos cuja raiz quadra-
da é igual à soma dos seus dois primeiros e dois últimos dígitos */

int main(void)
{

  int numero, DD, dd;

  for (numero = 1000; numero <= 9999; numero++) {
    DD = numero / 100;
    dd = numero % 100;
    if ( (DD + dd) * (DD + dd) == numero ){
      printf("%d\n", numero);
    }
  }
  return 0;
}
