#include <stdio.h>

int main(void)
{
  int n , pot , resto , decimal;

  printf("Entre com um número binario: ");
  scanf("%d", &n);

  decimal = 0;
  pot = 1;

  do{
     resto = n % 2;
     n = n / 10;
     decimal = decimal + (resto * pot);
     pot = pot * 2;
  } while(n>0);


  printf("Decimal = %d.\n",decimal);

  return 0;
}
