#include <stdio.h>
/*Aluno: Augusto Cesar de Aquino Ribas
Algoritmos de programação turma 03
Analise de sistemas.*/

/*Esse programa imprime um vetor na ordem crescente usando a função menores*/

/*Função que conta quantos valores menores que x ha no vetor */
int MENORES(int x, int V[], int n){
  int cont=0, i;

  for(i=0;i<n;i++) {

    if(V[i]<x) {
      cont++;
    }
  }

  return cont;
}

int main(void)
{
  int n , i, vetor[100] , maior=0 , aux=0 ,valor ;


  /*Entrada de dados*/
  printf("Entre com o tamanho do vetor: ");
  scanf("%d",&n);

  printf("Entre com os elementos do vetor: ");
  for(i=0;i<n;i++){
  scanf("%d",&vetor[i]);
  }

  /*Encontrando o maior valor de retorno da função menores para o vetor fornecido*/
  for(i=0;i<n;i++){
    valor=MENORES(vetor[i],vetor,n);
    if(valor>maior) {
      maior=valor;
    }
  }

  /*Imprimindo os valores em ordem crescente (ou não descrecente)*/
  while(aux<=maior) {

  for(i=0;i<n;i++) {
    if(MENORES(vetor[i],vetor,n) == aux) {
      printf("%d ",vetor[i]);
	}
  }

  aux++;
  }

  printf("\n");
  return 0;
}
