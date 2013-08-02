#include <stdio.h>

int main(void)
{
  int V[100], J[100], menor, n,m,i,j=0,aux;

  /*Entrada de dados*/

  printf("Entre com o tamanho do vetor: ");
  scanf("%d",&n);

  printf("Entre com os elementos do vetor :\n");
  for(i=0;i<n;i++) {
    scanf("%d",&V[i]);
  }

  /*Processamento*/

  /*Primeiro copiamos o n em m para poder utilizar ele*/
  m=n;

  /*Vamos ter que realizar essa parte para todos os m elementos*/
  for(j=0;j<m;j++) {

    /*Primeiro iniciamos o menor com o primeiro elemento e zeramos o aux*/
    menor=V[0];
    aux=0;

    /*Depois percorremos todo o vetor de entrada procurando o menor valor*/
    for(i=0;i<n;i++) {

      if(menor>V[i]) {
	/*Então salvamos o menor valor*/
	menor=V[i];
	/*E a sua posição*/
	aux=i;
      }

    }

    /*O menor valor será então colocado na primeira posição do vetor de saida*/
    J[j]=menor;

    /*Como a posição V[aux] não é mais necessaria, vamos copiar o ultimo valor
      do vetor de entrada nele*/
    V[aux]=V[n-1];

    /*E como existem duas copias agora do ultimo elemento, não precisamos mais
      olhar o ultimo elemento duas vezes, então decrementamos o tamanho do 
      vetor de entrada n, assim no laço interno vai diminuindo*/
    n--;

  }


  /*Saida de dados */

  printf("-------------------------------------\n");
  printf("Saida\n");
  printf("-------------------------------------\n");

  for(i=0;i<m;i++) {
    printf("%d ",J[i]);
  }
  printf("\n");


  return 0;
}
