#include <stdio.h>

int main(void)
{
  int n , a , b ;

  printf("Entre com um número: ");
  scanf("%d", &n);

  a = n / 2;
  b = n / 3;

  printf("O quociente da divisão por 2 é %d e por 3 é %d.\n", a , b );

  return 0;
}
 
