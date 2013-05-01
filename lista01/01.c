#include <stdio.h>
/*Esse programa pega tres números inteiros a, b, e c e resolve a equação a*b+c*/
int main(void)
{
  int a , b , c , resul;
  printf("Informe três números: ");
  scanf("%d %d %d", &a, &b, &c);

  resul = a * b + c;

  printf("O resultado de %d * %d + %d é %d.\n",a,b,c,resul);

  return 0;
}
