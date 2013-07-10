#include <stdio.h>

int main(void)
{
  int i, j , n , vetor[100] , aux;

  scanf("%d",&n);

  for(i=0;i<n;i++)
    scanf("%d",&vetor[i]);

  for(i=0;i<(n-1);i++) {
    for(j=i;j<(n-1);j++){

      if(vetor[j]>vetor[j+1]) {
	aux=vetor[j+1];
	vetor[j+1]=vetor[j];
	vetor[j]=aux;
      }

    }
  }

  for(i=0;i<n;i++)
    printf("%d ",vetor[i]);

  printf("\n");

  return 0;
}
