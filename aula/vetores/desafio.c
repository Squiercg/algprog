#include <stdio.h>

/*Dada uma sequência de n números inteiros, determinar um segmento de soma máxima.*/

int main(void)
{
  int n , i , maior , dif , inicio , fim , soma, vetor[100] = {0};

  /*Entrada de dados, pegando o n e preenchendo o vetor*/
  scanf("%d",&n);

  for(i=0 ; i<n ; i++) {
    scanf("%d",&vetor[i]);
  }

  /*Iniciando o maior como o menor valor inteiro possivel*/
  maior = -2147483647;
  dif = 0;

  /*A maior diferença possivel vai ser do zero de 0 a n-1,
    ja o vetor começa no n=0 e termina no n-1*/
  while(dif<=(n-1)) {


  /*Iniciando o inicio e fim do pedaço do vetor a somar*/
    inicio=0;
    fim=0;

  /*Aqui eu vou adicionar uma diferença no fim, a primeira vai ser 0, de 1 em 1 item
    do vetor, mas conforme a dif aumenta, eu somarei de 2 em 2, 3 em 3 até n-1 em n-1*/
    fim=fim+dif;

  /*Tudo pronto eu entre nesse loop que vai percorrer o vetor até o ultimo item, n-1, eu vou entrar aqui
    mesmo que não va percorrer o vetor, quando inicio = 0 e fim = n-1*/
    while(fim<=(n-1)) {

      soma=0;

      for(i=inicio;i<=fim;i++) {
	soma=soma+vetor[i];
      }

      if(soma>maior) {
	maior=soma;
      }

  /*Apos percorrer um item e ver se a soma dele é maior que o ultimo caso, eu avanço uma casa no vertor*/
      inicio++;
      fim++;

    }

  /*Por fim eu aumento uma vez a diferença*/
    dif++;

  }

  /*E finalmente eu imprimo o resultado*/
  printf("%d\n",maior);


  return 0;
}
