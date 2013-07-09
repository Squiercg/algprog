#include <stdio.h>
/*Aluno: Augusto Cesar de Aquino Ribas
Algoritmos de programação turma 03
Analise de sistemas.*/

/*Esse programa conta quantas repetições cada elemento do vetor possui e copia essa informação nele*/


/*Função que conta quantos repetições um elemento do vetor tem*/
int crepetidos(int a[], int indice) {
  int i=0, contagem=0;

  while(a[i]!=0) {
    if(a[indice]==a[i]) {
      contagem++;
    }
    i++;
  }

  return contagem;
}

int main(void)
{
  int i=0 , vetor[100], saida[100];

  /*Entrada de dados*/
  printf("Entre com um vetor, coloque um zero para finalizar a entrada do vetor:\n");
  scanf("%d",&vetor[i]);

  while(vetor[i]!=0) {
    i++;
    scanf("%d",&vetor[i]);
  }

  /*Processamento*/
  /*Contando o número de repetições*/
  i=0;
  while(vetor[i]!=0) {
    saida[i]=crepetidos(vetor,i);
    i++;
  }

  /*Copiando a resposta para o vetor original como o exercicio pede*/
  i=0;
  while(vetor[i]!=0) {
    vetor[i]=saida[i];
    i++;
  }

  /*Saida*/
  i=0;
  while(vetor[i]!=0) {
    printf("%d ",vetor[i]);
    i++;
  }

  printf("\n");

  return 0;
}
