#include <stdio.h>

#define MAX 100

void bubblesort(int vetor[MAX], int n) {
  int i , j , aux;

  for(i=0;i<n-1;i++) {
    for(j=0;j<n-i-1;j++) {
      if(vetor[j]>vetor[j+1]) {
	aux=vetor[j];
	vetor[j]=vetor[j+1];
	vetor[j+1]=aux;
      }
    }
  }

}

void bubblesortR(int vetor[MAX], int ini, int n) {
  int aux;

  if(n==1) {

  } else {
    if(ini<(n-1)) {
      if(vetor[ini]>vetor[ini+1]) {
	aux=vetor[ini];
	vetor[ini]=vetor[ini+1];
	vetor[ini+1]=aux;
      }
      bubblesortR(vetor,ini+1,n);
    } else {
      bubblesortR(vetor,0,n-1);
    }
  }
}

int main(void){
  int n, i ,vetor1[MAX],vetor2[MAX];

  scanf("%d",&n);

  for(i=0;i<n;i++) {
    scanf("%d",&vetor1[i]);
  }

  for(i=0;i<n;i++) {
    vetor2[i]=vetor1[i];
  }


  bubblesort(vetor1,n);

  printf("Bubble Sort iterativo:\n");
  for(i=0;i<n;i++) {
    printf("%d ",vetor1[i]);
  }
  printf("\n");

  bubblesortR(vetor2,0,n);

  printf("Bubble Sort recursivo:\n");
  for(i=0;i<n;i++) {
    printf("%d ",vetor2[i]);
  }
  printf("\n");


  return 0;
}
