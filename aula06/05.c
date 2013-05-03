#include <stdio.h>

/*Imprimi as n primeiras potencias de 2*/

int main(void)
{

  int n , pot , contador ;
  printf("Entre com o número de potências desejadas: ");
  scanf("%d",&n);

  pot = 1;
  contador = 1;

  while(contador <=n) {
    printf("%d ",pot);
    pot = pot * 2;
    contador = contador + 1;
  }

  printf("\n");
  return 0;

}
