#include <stdio.h>

/*Dadas duas sequencias com n e m (n, m ≤ 100) numeros inteiros entre 0 e 9,
interpretadas como dois numeros inteiros de n e m algarismos, calcular a sequencia
de numeros que representa a soma dos dois inteiros.*/

int main(void)
{
  int a[100] , b[100] , soma[100] ;
  int cont1, cont2, i , carry , contmaior;

  /*Entrada de dados*/
  cont1=0;
   scanf("%d",&a[cont1]);

  while(a[cont1]!=-1) {
    cont1++;
    scanf("%d", &a[cont1]);
  }

  cont2=0;
  scanf("%d",&b[cont2]);

  while(b[cont2]!=-1) {
    cont2++;
    scanf("%d", &b[cont2]);
  }

  /**/
  /*Processamento dos dados*/
  /**/

  /*Iniciando o carry com zero*/
  carry=0;

  /*Primeiro verificamos o tamanho dos vetores, se algum for menor, ele tem que ser empurrado
    para frente para a soma ficar correta*/

  /*Nesse caso o vetor b é o menor*/
  if(cont1 > cont2) {


  /*Então vamos caminhar no vetor a*/
    for(i=cont1 - 1 ; i>=(cont1-cont2) ; i--) {
  /*A cada passo o vetor b é empurrado a frente uma distancia igual a diferença do tamanho dele para o tamanho a*/
      soma[i]=a[i]+b[i-(cont1-cont2)]+carry;
  /*Depois disso guardamos um possivel carry caso seja necessario*/
      carry = soma[i] / 10;
  /*E deixamos um número de 0 a 9 (modulo 10) no lugar do número*/
      soma[i] = soma[i] % 10;
    }

    /*Agora para fechar, terminamos de completar o vetor soma com o resto de a*/
    for(i=(cont1-cont2) - 1 ; i>=0 ; i--) {
      soma[i]=a[i];
    }



  } else {

  /*Aqui é a mesma ideia, so que com b sendo maior que a*/

    if(cont1 < cont2) {


      for(i=cont2 - 1 ; i>=(cont2-cont1) ; i--) {
      soma[i]=a[i-(cont2-cont1)]+b[i]+carry;
      carry = soma[i] / 10;
      soma[i] = soma[i] % 10;
      }

      for(i=(cont2-cont1) - 1 ; i>=0 ; i--) {
	soma[i]=b[i];
      }


    } else {

  /*Existe ainda a possibilidade de a ser igual a b, essa possibilidade aqui*/
      for(i=cont2 - 1 ; i>=(cont2-cont1) ; i--) {
      soma[i]=a[i]+b[i]+carry;
      carry = soma[i] / 10;
      soma[i] = soma[i] % 10;
      }

    }
  }

  /*Fim do processamento*/

  /*Saida*/

  if(cont1>=cont2) {
    contmaior = cont1;
  } else {
    contmaior = cont2;
  }

  for(i=0 ; i < contmaior ; i++) {
    printf("%d ",soma[i]);
  }

  printf("\n");

  return 0;
}
