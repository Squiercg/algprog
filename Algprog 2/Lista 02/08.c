/*Exercicio 8*/
#include<stdio.h>

int josephus(int n,int k) {
  int r, i;

  r = 0;
  i = 2;
  while(i<=n) {
    r = (r + k) % i;
    i=i + 1;
  }
  return r+1;

}

int main(void) {
  int n, k;

  printf("Entre com o numero de soldados e o intervalo das mortes:");
  scanf("%d %d",&n, &k);

  printf("Josephus deve iniciar na posicao %d\n",josephus(n,k));

  return 0;
}
