#include <stdio.h>

/**/

int main(void)
{
  int entradas, computados ,num , passo , soma , final;

  final = 0;
  scanf("%d",&entradas);

  computados=1;

  while(computados<=entradas) {
    scanf("%d",&num);
    passo=2;
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

  }

    printf("%d\n",final);

  return 0;

}
