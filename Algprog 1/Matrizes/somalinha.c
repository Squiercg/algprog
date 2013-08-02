#include <stdio.h>

int main(void) 
{
  int matriz[100][100] , m , n , i, j, a ,b, k,l ;

  scanf("%d %d",&n , &m);

  for(i=0;i<n;i++)
    for(j=0;j<m;j++)
      scanf("%d",&matriz[i][j]);

  scanf("%d %d",&a , &b);
  scanf("%d %d",&k , &l);

 for(j=0;j<m;j++)
   matriz[b-1][j] = matriz[a-1][j] +  matriz[b-1][j] ;

 for(j=0;j<m;j++)
   matriz[l-1][j] = matriz[l-1][j] *  matriz[k-1][j] ;

 for(i=0;i<n;i++){
   for(j=0;j<m;j++){
     printf("%d ",matriz[i][j]);
   }
   printf("\n");
 }

  return 0;
}
