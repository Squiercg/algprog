#include <stdio.h>

int main(void)
{
  int n , pot , resto , binario;

  printf("Entre com um número decimal: ");
  scanf("%d", &n);

  binario = 0;
  pot = 1;

  do{
     resto = n % 2;
     n = n / 2;
     binario = binario + (resto * pot);
     pot = pot * 10;
  } while(n>0);


  printf("Decimal = %d.\n",binario);

  return 0;
}
