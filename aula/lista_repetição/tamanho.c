#include <stdio.h>

int main(void)
{
  int n , i , numero, digitos ;

  scanf("%d" , &n);

  for( i=1 ; i<=n ; i++ ) {

    scanf("%d" , &numero );
    digitos=0;

    do {

      numero = numero / 10;
      digitos++;
    } while( numero > 0 );

    printf("%d\n",digitos);

  }

  return 0;

}


