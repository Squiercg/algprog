#include<stdio.h>

int crepetidos(int a[], int indice) {
  int i=0, contagem=0;

  while(a[i]!=0) {
    if(a[indice]==a[i]) {
      contagem++;
    }
    i++;
  }

  return contagem;
}

int main(void)
{
  int i=0 , vetor[100], saida[100];

  scanf("%d",&vetor[i]);

  while(vetor[i]!=0) {
    i++;
    scanf("%d",&vetor[i]);
  }

  i=0;
  while(vetor[i]!=0) {
    saida[i]=crepetidos(vetor,i);
    i++;
  }

  i=0;
  while(vetor[i]!=0) {
    printf("%d ",saida[i]);
    i++;
  }

  printf("\n");

  return 0;

}
