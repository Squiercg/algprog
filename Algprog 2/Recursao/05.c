#include <stdio.h>

int soma_digitos(int n) {
  int soma;

  soma=0;

  do{
    soma=soma+n%10;
    n=n/10;
  } while(n>0);

  return soma;

}

int soma_digitosR(int n) {
  int soma;

  if((n/10)==0) {
    soma=n;
  } else {
    soma=n%10+soma_digitosR(n/10);
  }

  return soma;

}



int main(void)
{
  int n;

  scanf("%d",&n);

  printf("Função iterativa: Soma dos digitos é %d\n",soma_digitos(n));
  printf("Função recursiva: Soma dos digitos é %d\n",soma_digitosR(n));

  return 0;

}

