#include <stdio.h>

void quadrado(int vetor1[] , int vetor2[]) {
  int i;

  for(i=0;i<10;i++){
    vetor2[i]=vetor1[i]*vetor1[i];
  }

}

int main(void)
{
  int vetor1[10] , vetor2[10] , i ;
  /*Entrada*/
  for(i=0;i<10;i++){
    scanf("%d",&vetor1[i]);
  }

  /*Processamento*/
  quadrado(vetor1,vetor2);


  /*Saida*/
  for(i=0;i<10;i++){
    printf("%d ",vetor2[i]);
  }

  //  printf("\n");

  return 0;
}
