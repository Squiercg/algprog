#include <stdio.h>

int main(void)
{
  int n , entrada , contador ;
  float soma , quantidade;

  entrada = 4;
  contador = 1;
  soma = 0;
  quantidade = 0;

  while(contador <= entrada ) {
    scanf("%d",&n);
    if( n%2 == 0) {
      soma = soma + n;
      quantidade = quantidade + 1;
    }
    contador++;
  }
  if(quantidade>0)
    printf("%.2f\n",soma/quantidade);
  else
    printf("%.2f\n",quantidade);

  return 0;
}
