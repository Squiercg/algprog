#include <stdio.h>

#define MAX 100
void selectionsort(int vetor[MAX],int n){
  int i, j, max, imax;

  for(i=n-1;i>0;i--) {
    max=vetor[0];
    imax=0;

    for(j=0;j<i;j++) {
      if(vetor[j]>max){
	max=vetor[j];
	imax=j;
      }


    }
      vetor[imax]=vetor[i];
      vetor[i]=max;
  }
}

/*
void selectionsortR(int vetor,int n){

}
*/


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

  /*
  selectionsortR(vetor2,n);
  */

  for(i=0;i<n;i++) {
    printf("%d ",vetor2[i]);
  }
  printf("\n");



  return 0;
}
