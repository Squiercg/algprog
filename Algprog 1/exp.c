#include <stdio.h>

int main(void)
{
  int cont;
  float x, ep , fat , pot , e;

  scanf("%f %f", &x, &ep);

  cont = 1;
  fat = 1;
  pot = x;
  e = 1.0;

  while((pot/fat) >= ep) {
    e = e + (pot/fat);
    cont++;
    fat = fat * cont;
    pot = pot * x;
  }

  printf("%f\n",e);

  return 0;
}
