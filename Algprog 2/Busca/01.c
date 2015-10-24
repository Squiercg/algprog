#include <stdio.h>

#define MAX 100

/* Recebe um número inteiro n >= 0, um vetor de números intei-
ros v[0..n-1] e um número inteiro x e devolve k no intervalo
[0, n-1] tal que v[k] == x. Se tal k não existe, devolve n */

int busca_sequencial_sentinela(int n, int v[MAX+1], int x)
{
  int k;
  v[n] = x;
for (k = 0; v[k] != x; k++)
  ;
  return k;
}

int main(void)
{

  int n, i, vetor[MAX+1], x,k;

  scanf("%d",&n);

  for(i=0;i<n;i++) {
    scanf("%d",&vetor[i]);
  }

  scanf("%d",&x);

  k=busca_sequencial_sentinela(n,vetor,x);

  if(k==n) {
    printf("%d ausente\n",x);

  } else {
    printf("%d presente\n",x);

  }

  return 0;
}
