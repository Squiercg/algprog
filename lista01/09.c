#include <stdio.h>
/*Recebe o valor do tres lados de um triangulo e o classifica quanto ao tipo*/
int main(void)
{
  int a,b,c;

  printf("Entre com os tres lados do triangulo: ");
  scanf("%d %d %d", &a, &b, &c);

  if(a==b && b==c && a==c) {
    printf("O triângulo é equilátero.\n");
  } else {
    if(a!=b && b!=c && a!=c) {
      printf("O triângulo é escaleno.\n");
    } else {
      printf("O Triângulo é isósceles.\n");
    }
  }

  return 0;

}
