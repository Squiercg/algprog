#include <stdio.h>
/*
ArcTan de x = x - x^3/3 + X^5/5 - X^7/7 + ...

até |x^k/k| < 0.0001 , k impar 0<= x <= 1 , em radianos


*/



int main(void)
{
  int s;
  float at, termo, x, cont;

  scanf("%f",&x);

  s=1;
  at=x;
  termo=x;
  cont=1;


  while((termo/cont) >= 0.0001) {
    termo = termo * x * x;
    cont+=2;
    s=-1 * s;
    at= at + s * (termo/cont);
    printf("(%f / %f)\n",termo,cont);
  }

  printf("%6.3f\n",at);

  return 0;
}

