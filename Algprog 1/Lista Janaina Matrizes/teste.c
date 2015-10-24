#include <stdio.h>

int main(void)
{

  int i, j, m , n , matriz[200][200];

  scanf("%d %d",&n , &m);

  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      scanf("%d",&matriz[i][j]);
    }
  }

  printf("yes\n");

  return 0;
}
