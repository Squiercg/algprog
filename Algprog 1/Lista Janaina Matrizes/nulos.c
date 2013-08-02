#include <stdio.h> 

int main(void)
{
  int i, j, m , n , matriz[200][200],colsum,rowsum,col=0,row=0;

  scanf("%d %d",&n , &m);

  for(i=0;i<n;i++)
    for(j=0;j<m;j++)
      scanf("%d",&matriz[i][j]);


  for(i=0;i<n;i++){
    rowsum=0;

    for(j=0;j<m;j++)
      rowsum=rowsum+matriz[i][j];

    if(rowsum==0)
      row++;
  }

  for(j=0;j<m;j++){
    colsum=0;

    for(i=0;i<n;i++)
      colsum=colsum+matriz[i][j];

    if(colsum==0)
      col++;
  }


  printf("%d %d\n",row,col);



      


  return 0;
}
