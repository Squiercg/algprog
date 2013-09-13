#include <stdio.h>

#define MAX 100


void insertionsort(int vetor[MAX], int n) {
  int i,j,aux;

  for(i=1;i<n;i++) {
    aux=vetor[i];
    j=i-1;
    while(j>=0 && vetor[j]>aux) {
      vetor[j+1]=vetor[j];
      j=j-1;
    }
    vetor[j+1]=aux;
  }

}

void insertionsortR(int vetor[MAX], int n) {
  int i, aux;

  if(n>1) {
    insertionsortR(vetor,n-1);
    aux=vetor[n-1];
    i=n-1;
    while(vetor[i-1]>aux && i>=0 ) {
      vetor[i]=vetor[i-1];
      i--;
     }
    vetor[i]=aux;
  }
}

int main(void) {

 int n, i ,vetor1[MAX],vetor2[MAX];

  scanf("%d",&n);

  for(i=0;i<n;i++) {
    scanf("%d",&vetor1[i]);
  }

  for(i=0;i<n;i++) {
    vetor2[i]=vetor1[i];
  }

  printf("Insertion Sort iterativo:\n");

  insertionsort(vetor1,n);

  for(i=0;i<n;i++) {
    printf("%d ",vetor1[i]);
  }
  printf("\n");

  printf("Insertion Sort recursivo:\n");

  insertionsortR(vetor2,n);

  for(i=0;i<n;i++) {
    printf("%d ",vetor2[i]);
  }
  printf("\n");



  return 0;
}
