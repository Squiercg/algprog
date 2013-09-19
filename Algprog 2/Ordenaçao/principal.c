#include <stdio.h>
#include <stdlib.h>
#include "ordena.h"

#define teste 5

int main(void){

  int i, vetor[MAX];

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

  /*Merge Sort*/

  for(i=0;i<teste;i++)
    vetor[i]=rand();

  for(i=0;i<teste;i++)
    printf("%d ",vetor[i]);
  printf("\n");

  mergesort(0,teste,vetor);

  printf("Merge Sort\n");
  for(i=0;i<teste;i++)
    printf("%d ",vetor[i]);
  printf("\n\n");



}
