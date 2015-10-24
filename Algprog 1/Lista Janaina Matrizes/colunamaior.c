#include <stdio.h> 

int main(void)
{
  int i, j, m , n , matriz[200][200],colsum=0,colsumaux=0,col=0;

  scanf("%d %d",&n , &m);

  for(i=0;i<n;i++)
    for(j=0;j<m;j++)
      scanf("%d",&matriz[i][j]);


  for(j=0;j<m;j++){
    colsum=0;

    for(i=0;i<n;i++)
      colsum=colsum+matriz[i][j];

    if(colsum>colsumaux){
      col=j;
      colsumaux=colsum;
    }
  }

  printf("%d\n",col+1);

  return 0;
}
