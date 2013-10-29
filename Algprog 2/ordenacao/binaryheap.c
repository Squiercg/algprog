#include <stdio.h>
#include <limits.h>

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

void sobe(int n, int vetor[MAX], int i) {
  while (vetor[pai(i)] < vetor[i]) {
    troca(&vetor[i], &vetor[pai(i)]);
    i = pai(i);
  }
}

void constroi_max_heap(int n, int vetor[MAX]) {
  int i;
  for (i = n/2 - 1; i >= 0; i--) {
    desce(n, vetor, i);
  }
}

int consula_maxima(int n, int vetor[MAX]) {
  return vetor[0];
}

int extrai_maxima(int *n, int S[MAX]) {
  int maior;
  if (*n > 0) {
    maior = S[0];
    S[0] = S[*n - 1];
    *n = *n - 1;
    desce(*n, S, 0);
    return maior;
  }
   else
     return INT_MIN;
}

void aumenta_prioridade(int n, int S[MAX], int i, int p) {
  if (p < S[i]) {
    printf("ERRO: nova prioridade é menor que da célula\n");
  } else {
    S[i] = p;
    sobe(n, S, i);
   }
}

void insere_lista(int *n, int vetor[MAX], int p) {
  *n = *n + 1;
  vetor[*n] = p;
  sobe(*n, vetor, *n - 1);
}

void heapsort(int n, int S[MAX]) {
  int i;
  constroi_max_heap(n, S);
  for (i = n - 1; i > 0; i--) {
    troca(&S[0], &S[i]);
    n--;
    desce(n, S, 0);
  }
}


int main(void) {

  int n, i ,vetor[MAX], x, p;

  scanf("%d",&n);

  for(i=0;i<n;i++) {
    scanf("%d",&vetor[i]);
  }

  printf("Binary Heap:\n");

  /*Organizando o vetor como Maxheap*/

  constroi_max_heap(n,vetor);

  for(i=0;i<n;i++) {
    printf("%d ",vetor[i]);
  }
  printf("\n");

  /*Extrai o maior elemento*/

  printf("Extrai_maximo\n");

  extrai_maxima(&n,vetor);

  for(i=0;i<n;i++) {
    printf("%d ",vetor[i]);
  }
  printf("\n");

  /*Insere elemento*/

  printf("Entre com um número para inserir:");
  scanf("%d",&x);

  for(i=0;i<=n+1;i++) {
    printf("%d ",vetor[i]);
  }
  printf("\n");

  insere_lista(&n,vetor,x);

  for(i=0;i<n;i++) {
    printf("%d ",vetor[i]);
  }
  printf("\n");


  /* Altera prioridade  */

  printf("Entre com a posição e novo valor para um elemento:");
  scanf("%d %d",&p,&x);

  aumenta_prioridade(n,vetor,p,x);

  for(i=0;i<n;i++) {
    printf("%d ",vetor[i]);
  }
  printf("\n");

  return 0;
}
