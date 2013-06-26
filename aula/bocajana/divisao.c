#include <stdio.h> 

int main(void)
{
  int i, j,  n ;
  float matriz[200][200], maior;
  scanf("%d",&n);

  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      scanf("%f",&matriz[i][j]);


  for(i=0;i<n;i++){
    maior=0;

    for(j=0;j<n;j++){
      if(maior<matriz[i][j]){
	maior=matriz[i][j];
      }
    }
  

    for(j=0;j<n;j++){
      matriz[i][j]= matriz[i][j]/maior;
    }

  }

    for(i=0;i<n;i++) {
      for(j=0;j<n;j++) {
	printf("%.2f ",matriz[i][j]);
      }
      printf("\n");
    }

      


  return 0;
}

