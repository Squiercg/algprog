#include <stdio.h>

/* Esse programa pega tres números inteiros quaisquer e os organiza em ordem decrescente */

int main(void)
{
  int x , y , z , aux ;

  scanf("%d %d %d", &x,&y,&z);

  if(y>x) {
    aux=x;
    x=y;
    y=aux;
  }

  if(z>y) {
    aux=y;
    y=z;
    z=aux;
  }

  if(y>x) {
    aux=x;
    x=y;
    y=aux;
  }

  printf("%d %d %d\n",x,y,z);

  return 0;

}
