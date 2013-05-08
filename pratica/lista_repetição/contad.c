#include <stdio.h>

int main(void)
{
  int n, d , numero , i, resto , contagem;

  scanf("%d %d", &n , &d );

  for(i=1 ; i<=n ; i++) {

    scanf("%d", &numero);
    contagem = 0;

    while(numero>0) {
      resto = numero % 10;
      numero = numero / 10;

      if(resto == d)
	contagem++;
    }

    printf("%d\n",contagem);

  }

  return 0;

}




