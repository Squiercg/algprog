#include <stdio.h>

int main(void)
{
  int n, n2, m, resto ;

  printf("Entre com um número: ");
  scanf("%d",&n);

  m=0;
  n2=n;

  do {
    resto = n % 10;
    n = n / 10;

    m = m*10 + resto;
  } while(n>0);

  if(n2==m)
    printf("É palindromo.\n");
  else
    printf("Não palindromo.\n");

  return 0;
}



