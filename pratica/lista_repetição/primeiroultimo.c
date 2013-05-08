#include <stdio.h>

int main(void)
{
  int n , numero , i , primeiro , ultimo;

  scanf("%d", &n);

  for(i=1 ; i<=n ; i++) {

    scanf("%d", &numero );

    primeiro = numero % 10;
    numero = numero / 10;

    while(numero>0) {

      ultimo = numero % 10;
      numero = numero / 10;

    }

    if(primeiro == ultimo)
      printf("yes\n");
      else
	printf("no\n");
  }
    return 0;
}
