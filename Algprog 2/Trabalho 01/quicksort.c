#include <stdio.h>
#define MAX 100

void troca(int *x , int *y){
  int aux;
  aux=*x;
  *x=*y;
  *y=aux;
}

int separa(int p, int r, int vetor[2][MAX]) {
  int x, i, j;
  x = vetor[1][p];
  i = p - 1;
  j = r + 1;
  while (1) {
    do {
      j--;
    } while (vetor[1][j] > x);
    do {
      i++;
    } while (vetor[1][i] < x);
    if (i < j) {
      troca(&vetor[0][i], &vetor[0][j]);
      troca(&vetor[1][i], &vetor[1][j]);
    } else {
      return j;
    }
  }
}

/* Recebe um vetor v [p..r-1] e o rearranja em ordem crescente */
void quicksort(int p, int r, int vetor[2][MAX]) {
  int q;

  if (p < r) {
    q = separa(p, r, vetor );
    quicksort(p, q, vetor );
    quicksort(q+1, r, vetor );
  }

}

int main(void) {

 int n, i ,vetor[2][MAX];

  scanf("%d",&n);

  for(i=0;i<n;i++) {
    vetor[0][i]=i;
    scanf("%d",&vetor[1][i]);
  }

  printf("Quickort:\n");

  quicksort(0,n-1,vetor);

  for(i=0;i<n;i++) {
    printf("%d ",vetor[0][i]);
  }
  printf("\n");
  for(i=0;i<n;i++) {
    printf("%d ",vetor[1][i]);
  }

  printf("\n");

  return 0;
}
