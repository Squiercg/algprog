#include <stdio.h>

/* Esse programa recebe dois valores, x e n.
O valor x será aproximado pela formula usando os n primeiros termos.
Formula=(-1)^k*((x^2k)/(2k!))
*/

int main(void)
{
  int cont , s , n , i ;
  float x , cos , fat , pot ;

  printf("Entre com os valores de x e n: ");
  scanf("%f %d", &x, &n );

  pot = x * x;
  cos = 1;
  fat = 2;
  s = -1;
  cont = 4;

  for(i=1 ; i<=n ; i++) {

    cos = cos + s * (pot/fat);
    pot = pot * x * x;
    fat = fat * (cont-1) * cont;
    s = -1 * s;
    cont = cont + 2;

  }

  printf("O valor aproximado de do coseno é %f.\n",cos);

  return 0;

}
