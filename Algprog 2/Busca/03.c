#include <stdio.h>

#define MAX 100

/*
int buscaR2(int n, int v[MAX], int x)
{
  if (v[n-1] == x)
    return 1;
  else
    return buscaR2(n-1, v, x);
}

Esse codigo está errado, o primeiro problema é que o caso base não inclue o caso de ausencia do valor x buscado.
Outro problema é que ele busca outros locais da memoria, é precisa limitar a recursão para nao buscar além do inico
do vetor.

*/

int buscaR2(int n, int v[MAX], int x)
{

  printf("vetor[n-1]=%d , n=%d , x=%d\n",v[n-1],n,x);
  if (v[n-1] == x)
    return 1;
  else
    if(n>1) {
      return buscaR2(n-1, v, x);
    } else {
      return -1;
    }
}

int main(void)
{
  int n, i, vetor[MAX+1],x;

  scanf("%d",&n);

  for(i=0;i<n;i++) {
    scanf("%d",&vetor[i]);
  }

  scanf("%d",&x);

  if(buscaR2(n,vetor,x)==1) {
    printf("%d está presente\n",x);
  } else {
    printf("%d está ausente\n",x);
  }

  return 0;
}
