#include <stdio.h>

int main(void)
{
  int n , i;
  float  n1 , n2 , soma;

  n1=1;
  n2=1;
  soma=0;

  printf("Entre com n: ");
  scanf("%d", &n);

  for(i=1 ; i<=n ; i++) {
    soma = soma + ( n1/n2 );
    n1 = n1 + 2;
    n2 = n2 + 1;
  }

  printf("O resultado é %.2f.\n",soma);

  return 0;
}
