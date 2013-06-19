#include <stdio.h>

/* Recebe dois números inteiros e imprime sua soma */

int main(void)
{
  int num1 , num2 , soma ;

  printf("Informe um número: \n");
  scanf("%d" , &num1 ) ;
  printf( "Informe outro número: \n");
  scanf("%d" , &num2 ) ;

  soma = num1 + num2 ;

  printf("A soma de %d mais %d é %d\n" , num1 , num2 , soma);

  return 0;
}
