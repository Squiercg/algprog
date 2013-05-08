#include <stdio.h>

/*Esse programa calcula x^n*/

int main(void)
{

  int n , x , resultado , contador ;
  printf("Entre com os valores de x e n: ");
  scanf("%d %d", &x , &n);

  resultado = 1;
  contador = 1;

  while(contador <=n) {
    resultado = resultado * x;
    contador = contador + 1;
  }

  printf("O resultado de %d elevado a %d é %d.\n", x , n , resultado);
  return 0;

}
