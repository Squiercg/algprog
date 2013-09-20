#include <stdio.h>
#define MAX 100

void troca(int *x , int *y){
  int aux;
  aux=*x;
  *x=*y;
  *y=aux;
}

int separa(int p, int r, int vetor[MAX]) {
  int x, i, j;
  x = vetor[p];
  i = p - 1;
  j = r + 1;
  while (1) {
    do {
      j--;
    } while (vetor[j] > x);
    do {
      i++;
    } while (vetor[i] < x);
    if (i < j) {
      troca(&vetor[i], &vetor[j]);
    } else {
      return j;
    }
  }
}

/* Recebe um vetor v [p..r-1] e o rearranja em ordem crescente */
void quicksort(int p, int r, int vetor[MAX]) {
  int q;

  if (p < r) {
    q = separa(p, r, vetor );
    quicksort(p, q, vetor );
    quicksort(q+1, r, vetor );
  }

}

int main(void) {

 int n, i ,vetor[MAX];

  scanf("%d",&n);

  for(i=0;i<n;i++) {
    scanf("%d",&vetor[i]);
  }

  printf("Quickort:\n");

  quicksort(0,n-1,vetor);

  for(i=0;i<n;i++) {
    printf("%d ",vetor[i]);
  }
  printf("\n");

  return 0;
}
