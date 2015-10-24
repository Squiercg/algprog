#include <stdio.h>

/*Calcula o fatorial de n*/

int main(void)

{
  int n, fatorial, contador;
  printf("Informe n: ");
  scanf("%d", &n);

  contador = 1;
  fatorial = 1;

  while (contador <= n) {
    fatorial = fatorial * contador;
    contador = contador + 1;
  }

  printf("O fatorial de  %d é %d.\n",n,fatorial);
  return 0;

}
