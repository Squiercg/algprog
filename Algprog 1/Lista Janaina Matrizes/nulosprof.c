#include <stdio.h>

int main(void)
{

  int m , n , A[100][100] , V[100]={0} , i , j , aux, L=0,C=0;

  scanf("%d %d", &m , &n);

  for(i=0;i<m;i++) {
    aux=0;

    for(j=0;j<n;j++) {

      scanf("%d", &A[i][j]);
      aux=aux+A[i][j];
      V[j]=V[j]+A[i][j];
    }

    if(aux==0)
      L++;
  }

  for(i=0;i<n;i++) {
    if(V[i]==0)
      C++;
  }

    printf("%d %d\n",L,C);

    return 0;
  }
