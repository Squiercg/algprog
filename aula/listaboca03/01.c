#include <stdio.h>

int main(void)
{

  int i, j, a, v, y[2][1000]={{0}}, x[2][100]={{0}}, aux[2];

  for(i=0;i<100;i++) {
    x[0][i]=i+1;
  }

  /*Entrada de dados*/
  printf("Entre com o número de aeroportos e voos: ");
  scanf("%d %d",&a, &v);

  for(i=0;i<v;i++) {
    printf("Voo %d: ",i+1);
    scanf("%d %d", &y[0][i], &y[1][i]);
  }

  /*Computando voos por aeroporto*/
  for(i=0;i<v;i++){
    x[1][y[0][i]-1]++;
    x[1][y[1][i]-1]++;
  }

  /*Ordenando com o algoritimo da bolha*/
  for(i=(v-1);i>=1;i--){
    for(j=0;j<i;j++){
	  printf("Comparando %d com %d\n",j,j+1);
	if(x[1][j]<x[1][j+1]){
	  aux[0]=x[0][j+1];
	  aux[1]=x[1][j+1];
	  x[0][j+1]=x[0][j];
	  x[1][j+1]=x[1][j];
	  x[0][j]=aux[0];
	  x[1][j]=aux[1];
	}

      }
  }
  printf("\n");

  for(i=0;i<a;i++){
    printf("A:%d,C:%d\n",x[0][i], x[1][i]);
  }


  /*Saida*/
  if(x[0][0]==x[0][1]){
    printf("Aeroportos: \n");
    printf("%d ",x[0][0]);
    i=1;
    while(x[0][i]==x[0][0]) {
    printf("%d ",x[0][i]);
    i++;
    }
  } else {
    printf("Aeroporto: \n");
    printf("%d ",x[0][0]);
  }

  printf("\n");


  return 0;
}
