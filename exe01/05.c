#include <stdio.h>
/*Entre com o valor de i e j e sera retornado o menor inteiro m maior que i e multiplo de f*/

int main(void) 
{
  int i , j , m ;

  printf("Entre com os valores i e j: ");
  scanf("%d %d", &i , &j );

  m = i + j - ( i % j );

  printf("O menor inteiro é %d.\n" , m );

  return 0;
}
