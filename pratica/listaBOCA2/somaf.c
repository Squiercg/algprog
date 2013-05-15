#include <stdio.h>

int main(void)
{

  int n , i , numerador, denominador ;
  float soma;
  scanf("%d", &n );
  
  numerador = 1;
  denominador = n;
  soma = 0.0;

  for(i=1 ; i<=n ; i++ ) {
    soma = soma + (float) numerador / (float) denominador;
    numerador++;
    denominador--;
  }

  printf("%.2f\n",soma);

  return 0;
}
