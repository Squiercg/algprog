#include <stdio.h>

/*Esse programa da overflow no limite do inteiro positivo (2³¹-1)*/
/*i.e. quando a soma superar 2147483647*/
int main(void)
{

  int n, numero, soma;
  printf("Informe n: ");
  scanf("%d", &n);

  soma = 0;
  numero = 1;

  while (numero <= n) {
    soma = soma + numero;
    numero = numero + 1;
  }

  printf("Soma dos %d primeiros inteiros é %d\n", n, soma);

  return 0;

}
