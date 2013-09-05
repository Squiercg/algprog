#include <stdio.h>
#define MAX 100

/* Recebe um número inteiro n > 0, um vetor de números in-
teiros crescente v[0..n-1] e um número inteiro x e devol-
ve um índice k em [0, n] tal que v[k-1] < x <= v[k] */

int busca_binaria(int n, int v[MAX], int x) {
  int esq, dir, meio;
  esq = -1;
  dir = n;
  while (esq < dir - 1) {

    meio = (esq + dir) / 2;

    if (v[meio] < x) {
      esq = meio;
    } else {
      dir = meio;
    }

  }

return dir;
}

int main(void)
{
  int n, i, vetor[MAX] , x, local;

  scanf("%d %d",&n,&x);

  for(i=0;i<n;i++) {
    vetor[i]=i+1;
  }

  local=busca_binaria(n,vetor,x);

  printf("Vetor: ");

  for(i=0;i<n;i++) {
    printf("%d ",vetor[i]);
  }

  printf("\n");

  if(vetor[local]==x){
    printf ("%d presente.\n",x);
  } else {
    printf ("%d ausente.\n",x);
  }

  return 0;

}
