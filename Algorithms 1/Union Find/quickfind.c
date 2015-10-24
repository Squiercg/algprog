#include <stdio.h>
#include <stdlib.h>

void uniao(int p, int q , int vetor[] , int n) {
  int pid , qid , i;

  pid = vetor[p];
  qid = vetor[q];

  for (i = 0; i < n; i++) {
    if (vetor[i] == pid) {
      vetor[i] = qid;
    }
  }

}

void conectado(int p, int q, int vetor[]) {

  if(vetor[p]==vetor[q]) {
    printf("Existe um caminho\n");
  } else {
    printf("Não existe um caminho\n");
  }

}

int main(void){
  int *vetor;
  int i, n, a , b, arestas;

  printf("Entre com o número de vértices: ");

  scanf("%d",&n);

  vetor = malloc(n * sizeof(*vetor));

  for(i=0;i<n;i++) {
    vetor[i]=i;
  }

  printf("Entre com o número de arestas: ");
  scanf("\n%d",&arestas);

  printf("Entre com as arestas:\n");
  for(i=1;i<=arestas;i++) {
    scanf("\n%d %d",&a,&b);
    uniao(a-1,b-1,vetor,n);
  }

  printf("Entre com o valor de dois vértices validos\n");

  scanf("%d %d",&a,&b);

  while( (a>0 && a<=n) && (b>0 && b<=n) ) {
    conectado(a-1,b-1,vetor);
    scanf("%d %d",&a,&b);
  }

  return 0;
}
