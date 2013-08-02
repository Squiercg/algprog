#include <stdio.h>
/*Aluno: Augusto Cesar de Aquino Ribas
Algoritmos de programação turma 03
Analise de sistemas.*/

/* Esse programa recebe dados do estoque de varias filiais e contabiliza o estoque total da empresa*/


typedef struct {
  int filial , codigo;
  char nprod[101];
  float quantidade;
  int marca;
} registro;


int main(void)
{
  registro produto[100]= {{0}} ;
  int n, i ,j;
  float soma;

  /*Entrada de dados*/
  printf("Entre com o número de entradas: ");
  scanf("%d",&n);

  for(i=0;i<n;i++) {
    printf("Entrada %d.\n",i+1);
    printf("Filial: ");
    scanf("%d",&produto[i].filial);
    printf("Nome produto: ");
    scanf(" %[^\n]",produto[i].nprod);
    printf("Código: ");
    scanf("%d",&produto[i].codigo);
    printf("Quantidade: ");
    scanf("%f",&produto[i].quantidade);
    printf("\n");
  }

  /*Processamento e Saida*/
  printf("\nRelatorio Final.\n");
  for(i=0;i<n;i++) {

    if(produto[i].marca==0) {
      soma=0;

      for(j=i;j<n;j++) {

	if(produto[i].codigo==produto[j].codigo) {
	  soma=soma+produto[j].quantidade;
	  produto[j].marca=1;
	}

      }
      printf("%s: %.2f\n",produto[i].nprod,soma);

    }
  }

  return 0;
}
