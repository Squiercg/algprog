#include <stdio.h>

int main(void)
{
  int r , d , i ;
  float rvet[100] , dvet[100];

  /*Entrada*/
  scanf("%d",&r);

  for(i=0;i<r;i++) {
    scanf("%f",&rvet[i]);
  }

  scanf("%d",&d);

  for(i=0;i<d;i++) {
    scanf("%f",&dvet[i]);
  }

  /*Processamento*/

  for(i=0;i<r;i++) {
    rvet[i]=rvet[i]/2.23;
  }

  for(i=0;i<d;i++) {
    dvet[i]=dvet[i]*2.23;
  }

  /*Saida*/
  for(i=0;i<r;i++) {
    printf("%.2f ",rvet[i]);
  }

  printf("\n");

  for(i=0;i<d;i++) {
    printf("%.2f ",dvet[i]);
  }

  printf("\n");

  return 0;
}
