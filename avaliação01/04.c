#include <stdio.h>

/**/

int main(void)
{
  int entradas, computados ,num , passo , soma , final;

  final = 0;

    printf("Digite um entradas a avaliar: ");
    scanf("%d",&entradas);
    computados=1;

  do {

    printf("Digite a entrada %d: ",computados);
    scanf("%d",&num);

    passo = 2;
    soma = 0;

    while (passo < num) {
      if (num % passo != 0) {
	soma = soma + 1;
    }
      passo = passo + 1;
    }

    if( (soma == num-2)) {
      final = final + num;
    }

    computados++;

  } while(computados<=entradas);

    printf("A soma dos primos é %d.\n",final);

  return 0;

}
