#include <stdio.h>

#define MAX 100
void selectionsort(int vetor[MAX],int n){
  int i, j, max, imax;

  for(i=n;i>0;i--) {
    max=vetor[0];
    imax=0;

    for(j=0;j<i;j++) {
      if(vetor[j]>max){
	max=vetor[j];
	imax=j;
      }

    }
      vetor[imax]=vetor[i-1];
      vetor[i-1]=max;
  }
}


void selectionsortR(int vetor[MAX],int n){
  int max,imax,j;

  if(n>1){
    max=vetor[0];
    imax=0;

    for(j=0;j<n;j++) {
      if(vetor[j]>max){
	max=vetor[j];
	imax=j;
      }

    }
      vetor[imax]=vetor[n-1];
      vetor[n-1]=max;

      selectionsortR(vetor,n-1);
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

  printf("Selection Sort iterativo:\n");

  selectionsort(vetor1,n);

  for(i=0;i<n;i++) {
    printf("%d ",vetor1[i]);
  }
  printf("\n");

  printf("Selection Sort recursivo:\n");

  selectionsortR(vetor2,n);

  for(i=0;i<n;i++) {
    printf("%d ",vetor2[i]);
  }
  printf("\n");



  return 0;
}
