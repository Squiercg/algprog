#include <stdio.h>

int main(void)
{
  int quantidade , i ,n, n2, m, resto ;

  scanf("%d",&quantidade);

  for(i=1 ; i<=quantidade ; i++ ) {

    scanf("%d",&n);

    m=0;
    n2=n;

    do {
      resto = n % 10;
      n = n / 10;

      m = m*10 + resto;
    } while(n>0);

  if(n2==m)
    printf("yes\n");
  else
    printf("no\n");

  }

  return 0;
}



