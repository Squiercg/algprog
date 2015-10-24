#include <stdio.h>
/*Esse programa recebe um inteiro n e um inteiro k sendo, apos isso ele recebe
um vetor de tamanho n e retira o elemento de indice k desse vetor e imprime o
nov vetor.
Ele encerra quando os valores de n e k são zero*/


/*Essa função recebe um vetor, um inteiro n correspondente ao tamanho do vetor
e um inteiro k correspondente a indice do elemento a ser excluido do vetor.
Aqui eu teria feito uma função void, mas como no exercicio pede essa interface
então a função altera o vetor e retorna 0*/
int remover(int v[], int n, int k){
  int i;

  for(i=k;i<n;i++) {
    v[i]=v[i+1];
  }

  return 0;
}


int main(void)
{
  int n, k , vetor[100], i;

  /*Recebendo os primeiro valores n e k*/
  scanf("%d %d",&n , &k);

  /*Equanto esses são diferentes de zero o programa ira continuar*/
  while(n!=0 || k!=0) {

    /*Recebendo o vetor*/
    for(i=0;i<n;i++){
      scanf("%d",&vetor[i]);
    }

    /*Se o vetor é de tamanho 1 e sera retirado um elemento
basta imprimir uma linha vazia*/
    if(n==1) {

      printf("\n");

    } else {

      /*No caso de um vetor maior, usamos a função para remover o elemento k*/
      remover(vetor,n,k);

      /*Então imprimimos o vetor com k removido, que agora tem o tamanho um 
elemento menor (n-1)*/
      for(i=0;i<(n-1);i++){
	printf("%d ",vetor[i]);
      }

      printf("\n");
    }

    /*Então pegamos novos n e k*/
    scanf("%d %d",&n , &k);
  }

  /*Pelo exemplo, existe uma linha em branco apos o programa terminar*/
  printf("\n");

  return 0;
}
