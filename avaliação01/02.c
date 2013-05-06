#include <stdio.h>

/*Esse programa pega tres resultados referentes a uma amostra de aço e o classifica quanto a sua qualidade*/

int main(void)
{
  int carbono , dureza , resistencia , teste , resultado ;

  printf("Entre com os valores de conteudo de carbono, dureza e resistencia da amostra: ");
  scanf("%d %d %d",&carbono, &dureza , &resistencia);

  teste=0;

  if(carbono<=70) {
    teste++;
  }

  if(dureza>=50) {
    teste++;
  }

  if(resistencia>=80000) {
    teste++;
  }

  if(teste==3) {
    resultado = 10;
  } else {
    if(teste==2) {
      resultado =9;
    } else {
      if(teste==1) {
	resultado = 8;
      } else {
	resultado = 7;
      }
    }
  }

  printf("A classificação da amostra é %d.\n",resultado);
  return 0;

}



