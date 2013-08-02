#include <stdio.h>

int main(void)
{
  int n , inicial, resto , inverso;

  printf("Entre com um número: ");
  scanf("%d", &n);

  inicial = n;
  inverso = 0;

  do{
     resto = n % 10;
     n = n / 10;
     inverso = (inverso * 10) + resto;
  } while(n>0);


  printf("O inverso de %d é %d.\n", inicial , inverso);

  return 0;
}
