#include <stdio.h> 

int main(void)
{
  int i , j , n , diag = 0 , matriz[200][200];

  scanf("%d",&n);

  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      scanf("%d",&matriz[i][j]);

  for(i=0;i<n;i++){
    diag=diag+matriz[i][i];
  }

  printf("%d\n",diag);

  return 0;
}
