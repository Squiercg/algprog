#include <stdio.h> 

int main(void)
{
  int i, j, m , n , menor[2]={0,0} , matriz[200][200];

  scanf("%d %d",&n , &m);

  for(i=0;i<n;i++)
    for(j=0;j<m;j++)
      scanf("%d",&matriz[i][j]);


  menor[0]=matriz[0][0];

  for(i=0;i<n;i++){
    for(j=0;j<m;j++){

      if(menor[0]>matriz[i][j]){
	menor[0]=matriz[i][j];
	menor[1]=i;
      }

    }
  }

  printf("%d\n",menor[1]+1);

  return 0;
}
