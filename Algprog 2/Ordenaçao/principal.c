#include <stdlib>
#include ordena.h

int main(void){

  int i, vetor[MAX];

  /*Insertion Sort*/

  for(i=0;i<30;i++)
    vetor[i]=rand();

  for(i=0;i<30;i++)
    printf("%d ",vetor[i]);
  printf("\n");

  insertionsortR(vetor,30);

  printf("Insertion Sort\n");
  for(i=0;i<30;i++)
    printf("%d ",vetor[i]);
  printf("\n\n");

  /*Selection Sort*/

  for(i=0;i<30;i++)
    vetor[i]=rand();

  for(i=0;i<30;i++)
    printf("%d ",vetor[i]);
  printf("\n");

  selectionsortR(vetor,30);

  printf("Selection Sort\n");
  for(i=0;i<30;i++)
    printf("%d ",vetor[i]);
  printf("\n\n");

  /*Merge Sort*/

  for(i=0;i<30;i++)
    vetor[i]=rand();

  for(i=0;i<30;i++)
    printf("%d ",vetor[i]);
  printf("\n");

  mergesort(vetor,30);

  printf("Selection Sort\n");
  for(i=0;i<30;i++)
    printf("%d ",vetor[i]);
  printf("\n\n");



}
