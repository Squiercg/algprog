#include <stdio.h>

/*Imprime os n primeiros impares*/

int main(void)

{
  int n, numero, contador;
  printf("Informe n: ");
  scanf("%d", &n);

  contador = 1;
  numero = 1;

  while (contador <= n) {
    printf("%d , ",numero);
    numero = numero +2;
    contador = contador + 1;
  }

  printf(" Fim.\n");
  return 0;

}
