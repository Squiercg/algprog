#include <stdio.h>
/*Aluno: Augusto Cesar de Aquino Ribas
Algoritmos de programação turma 03
Analise de sistemas.*/

/* Esse programa recebe os dados de trafego aereo e estima qual ou quais
os aeroportos com mair risco de congestionamento*/

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
  /*Essa informção sera guardada numa matriz,
    a linha zero consiste no id do aerorporto e a linha 1
    consiste na quantidade de voos daquele aeroporto*/
  for(i=0;i<v;i++){
    x[1][y[0][i]-1]++;
    x[1][y[1][i]-1]++;
  }

  /*Ordenando  aeroportos com o algoritimo da bolha, note que ordenamos por
    quantidade, mas os id dos aeroportos também são organizados juntos*/
  for(i=(v-1);i>=1;i--){
    for(j=0;j<i;j++){
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

  /*Saida*/
  /*Comparamos se houve empate entre os primeiros, se houver nos listaremos
    todos os aeroportos com maior chance de congestionamento*/
  if(x[1][0]==x[1][1]){
    printf("Aeroportos: \n");
    printf("%d ",x[0][0]);
    i=1;
    while(x[1][i]==x[1][0]) {
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
