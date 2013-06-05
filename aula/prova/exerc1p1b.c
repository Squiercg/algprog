#include <stdio.h>
/* Aproxima o seno de um valor x com erro etipulado pelo usuario pela formula
Sen= (-1)^k * ( (x^(2k+1)) / (2k+1)! )
*/

int main(void)
{
  int cont, s;
  float x, erro , pot, fat, sen;

 scanf("%f %f", &x, &erro);

 sen = x;
 pot = x;
 fat = 1;
 cont = 3;
 s = -1;

  while((pot/fat)>=erro) {
    pot = pot * x * x;
    fat = fat * (cont-1) * cont;
    sen = sen + s * (pot/fat);
    cont = cont + 2;
    s=s * (-1);
  }

  printf("%f\n",sen);

  return 0;
}
