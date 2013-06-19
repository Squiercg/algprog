#include <stdio.h>

int main(void) {

  int matriz[100][100] , m , n , i, j, v , l;

  scanf("%d %d",&n , &m);

  for(i=0;i<n;i++)
    for(j=0;j<m;j++)
      scanf("%d",&matriz[i][j]);
 
  scanf("%d %d",&v , &l);

 for(j=0;j<m;j++)
   matriz[l-1][j] = matriz[l-1][j] * v;


 for(i=0;i<n;i++){
   for(j=0;j<m;j++){
     printf("%d ",matriz[i][j]);
   }
   printf("\n");
 }


  printf("\n");

  return 0;
}
