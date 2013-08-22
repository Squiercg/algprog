#include <stdio.h>

/* Recebe um dois números inteiros x e n e devolve x a n-ésima potência */

int pot(int x, int n) {
  int i, result;

  result = 1;

  for (i = 1; i <= n; i++) {
    result = result * x;
  }

  return result;

}

/* Recebe um dois números inteiros x e n e devolve x a n-ésima potência */
int potR(int x, int n) {

  if (n == 0) {
    return 1;
  } else {
    return x * potR(x, n-1);
  }
}

/* Recebe dois números inteiros x e n e imprime x a n-ésima potên-
cia chamando duas funções: uma não-recursiva e uma recursiva */

int main(void)
{
  int x, n;

  scanf("%d%d", &x, &n);

  printf("Não-resursiva: %d^%d = %d\n", x, n, pot(x, n));
  printf("Resursiva: %d^%d = %d\n", x, n, potR(x, n));

  return 0;
}
