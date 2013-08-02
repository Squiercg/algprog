#include <stdio.h>

/*Esse programa pega 3 inteiros e mostra a soma e multiplicação desses números*/

int main(void)
{
  int a,b,c,soma,mult;

  printf("Entre os valores de a b c: ");
  scanf("%d %d %d", &a , &b , &c );

  soma = a + b + c;
  mult = a * b * c;

  printf("O resultado da soma e %d e da multiplicacao e %d\n", soma , mult);

  return 0; 
 }
