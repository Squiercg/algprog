#include <stdio.h>

int main(void)
{
  int i, j, n, matriz[100][100];
  float vetor[11];


  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      scanf("%d",&matriz[i][j]);
    }
  }


  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
    vetor[matriz[i][j]]++;
    }
  }

  for(i=0;i<11;i++){
    printf("Número %d: %.2f\n", i , vetor[i]/ (n*n));
  }

  return 0;
}
