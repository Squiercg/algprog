#include <stdio.h>

/* Esse programa pega tres números, x, y e z quaisquer e os organiza de forma a z>=y>=x */

int main(void)
{
  int x , y , z , aux ;

  printf("Entre com 3 números inteiros para x y z: ");
  scanf("%d %d %d", &x,&y,&z);

  if(x>y) {
    aux=x;
    x=y;
    y=aux;
  }

  if(y>z) {
    aux=y;
    y=z;
    z=aux;
  }

  if(x>y) {
    aux=x;
    x=y;
    y=aux;
  }

  printf("O valores são agora x = %d, y = %d e z = %d.\n",x,y,z);

  return 0;

}
