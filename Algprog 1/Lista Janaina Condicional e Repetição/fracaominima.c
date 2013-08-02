#include <stdio.h>

int main(void)
{
  int n , i , contador , numerador , denominador , divisor , maxdiv;

  scanf("%d", &n);
  contador= 1;

  while(contador<=n) {
    scanf("%d %d", &numerador , &denominador);

      if(numerador<denominador)
	divisor = numerador;
      else
	divisor = denominador;

    maxdiv = 1;

    for(i=2 ; i<=divisor ; i++) {
      if(numerador % i == 0 && denominador % i == 0 ) {
	maxdiv = i;
      }
    }

    printf("%d %d\n",numerador /  maxdiv,  denominador / maxdiv);

    contador++;

  }

  return 0;

}
