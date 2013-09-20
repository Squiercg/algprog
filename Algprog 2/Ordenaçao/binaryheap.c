#include <stdio.h>

#define MAX 100

void troca(int *x , int *y){
  int aux;
  aux=*x;
  *x=*y;
  *y=aux;
}

int pai(int i) {
  if (i == 0)
    return 0;
   else
     return (i - 1) / 2;
}

int esquerdo(int i) {
  return 2 * (i + 1) - 1;
}

int direito(int i) {
  return 2 * (i + 1);
}

void desce(int n, int vetor[MAX], int i) {
  int e, d, maior;
  e = esquerdo(i);
  d = direito(i);
  if (e < n && vetor[e] > vetor[i])
    maior = e;
   else
     maior = i;
  if (d < n && vetor[d] > vetor[maior])
    maior = d;
  if (maior != i) {
    troca(&vetor[i], &vetor[maior]);
    desce(n, vetor, maior);
  }
}

void constroi_max_heap(int n, int vetor[MAX]) {
  int i;
  for (i = n/2 - 1; i >= 0; i--)
    desce(n, vetor, i);
}

int main(void) {

  int n, i ,vetor[MAX];

  scanf("%d",&n);

  for(i=0;i<n;i++) {
    scanf("%d",&vetor[i]);
  }

  printf("Binary Heap:\n");

  constroi_max_heap(n,vetor);


  for(i=0;i<n;i++) {
    printf("%d ",vetor[i]);
  }
  printf("\n");

  return 0;
}
