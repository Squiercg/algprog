#include <stdio.h>
#include <stdlib.h>
#include "ordena.h"

int main(void){

  int i, vetor[MAX] , teste;

  scanf("%d",teste);

  /*Insertion Sort*/

  for(i=0;i<teste;i++)
    vetor[i]=rand();

  for(i=0;i<teste;i++)
    printf("%d ",vetor[i]);
  printf("\n");

  insertionsortR(vetor,teste);

  printf("Insertion Sort\n");
  for(i=0;i<teste;i++)
    printf("%d ",vetor[i]);
  printf("\n\n");

  /*Selection Sort*/

  for(i=0;i<teste;i++)
    vetor[i]=rand();

  for(i=0;i<teste;i++)
    printf("%d ",vetor[i]);
  printf("\n");

  selectionsortR(vetor,teste);

  printf("Selection Sort\n");
  for(i=0;i<teste;i++)
    printf("%d ",vetor[i]);
  printf("\n\n");

  /*MergeSort*/

  for(i=0;i<teste;i++)
    vetor[i]=rand();

  for(i=0;i<teste;i++)
    printf("%d ",vetor[i]);
  printf("\n");

  mergesort(0,teste,vetor);

  printf("MergeSort\n");
  for(i=0;i<teste;i++)
    printf("%d ",vetor[i]);
  printf("\n\n");

  /*QuickSort*/

  for(i=0;i<teste;i++)
    vetor[i]=rand();

  for(i=0;i<teste;i++)
    printf("%d ",vetor[i]);
  printf("\n");

  //

  printf("QuickSort\n");
  for(i=0;i<teste;i++)
    printf("%d ",vetor[i]);
  printf("\n\n");

  /*BinaryHeap*/

  for(i=0;i<teste;i++)
    vetor[i]=rand();

  for(i=0;i<teste;i++)
    printf("%d ",vetor[i]);
  printf("\n");

  //

  printf("Binary Heap\n");
  for(i=0;i<teste;i++)
    printf("%d ",vetor[i]);
  printf("\n");


}
