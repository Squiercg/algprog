#include <stdio.h> 

int main(void)
{
  int i, j, m , n , maior[2]={0}, teste , matriz[200][200];

  scanf("%d %d",&n , &m);

  for(i=0;i<n;i++)
    for(j=0;j<m;j++)
      scanf("%d",&matriz[i][j]);

  for(i=0;i<n;i++){
    teste=0;
    for(j=0;j<m;j++){
      teste=teste+matriz[i][j];
    }
    if(teste>maior[0])
      maior[1]=i;
  }

  printf("%d\n",maior[1]+1);

  return 0;
}
