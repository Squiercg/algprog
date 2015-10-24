#include <stdio.h>

#define MAX 100

int remover(int n, int v[MAX], int k)
{
  int i;

  for(i=k;i<n;i++) {
    v[i-1]=v[i];
  }

  return n-1;

}

int removerR(int n, int v[MAX], int k)
{

  if(k==n) {

    return n-1;

  } else {

    v[k-1]=v[k];

    return(removerR(n,v,k+1));

  }



}

int main(void)
{

  int i, vetor1[MAX],vetor2[MAX] , k,n1,n2;

  /*Entrada de dados*/
  scanf("%d",&n1);

  for(i=0;i<n1;i++) {
    scanf("%d",&vetor1[i]);
  }

  scanf("%d",&k);


  /*Copiando o vetor 1 para vetor 2*/
  n2=n1;

  for(i=0;i<n2;i++) {
    vetor2[i]=vetor1[i];
  }


  /*Processamento*/
  n1=remover(n1,vetor1,k);

  n2=removerR(n2,vetor2,k);


  /*Saida de dados*/
  printf("Função iterativa:\n");
  for(i=0;i<n1;i++) {
    printf("%d ",vetor1[i]);
  }
  printf("\n");

  printf("Função recursiva:\n");
  for(i=0;i<n2;i++) {
    printf("%d ",vetor2[i]);
  }
  printf("\n");


  return 0;
}
