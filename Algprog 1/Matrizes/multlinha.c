#include <stdio.h>

int main(void) {

  int matriz[100][100] = {{0}} , m , n , i, j, v , l;

  /*Entrada*/

  /*Matriz*/
  scanf("%d %d",&n , &m);

  for(i=0;i<n;i++)
    for(j=0;j<m;j++)
      scanf("%d",&matriz[i][j]);
 
  /*V vezes linha escolhida*/
  scanf("%d %d",&v , &l);


  /*Processamento*/

 for(j=0;j<m;j++)
   matriz[l-1][j] = matriz[l-1][j] * v;



 /*Saida de dados*/

 for(i=0;i<n;i++){
   for(j=0;j<m;j++){
     printf("%d ",matriz[i][j]);
   }
   printf("\n");
 }

  printf("\n");

  return 0;
}
