#include <stdio.h>

/**/

int main(void)
{
  int num , passo , soma , final;

    final = 0;

  do {

    printf("Digite um número: ");
    scanf("%d",&num);

    passo = 2;
    soma = 0;

    while (passo < num) {
      if (num % passo != 0) {
	soma = soma + 1;
    }
      passo = passo + 1;
    }

    if( (soma == num-2) && (num > 0) ) {
      final = final + num;
    }

  } while(num > 0);

    printf("A soma dos primos é %d.\n",final);

  return 0;

}
