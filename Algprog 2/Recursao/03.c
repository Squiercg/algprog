#include <stdio.h>

int algeuclides(int a, int  b) {
  int divisor , dividendo, c;

  if(b > a) {
    dividendo = b;
    divisor = a;
  } else {
    dividendo = a;
    divisor = b;
  }


  while( (dividendo%divisor) != 0) {
    c=dividendo%divisor;
    dividendo = divisor;
    divisor=c;
  }

  return divisor;
}

int algeuclidesR(int a, int  b) {
  int resposta, divisor , dividendo;

  if(b > a) {
    dividendo = b;
    divisor = a;
  } else {
    dividendo = a;
    divisor = b;
  }

  if(divisor==0) {
    resposta=dividendo;
  } else {
    resposta=algeuclidesR(divisor,dividendo%divisor);
  }

  return resposta;
}

int main(void){
  int a, b;

  scanf("%d %d",&a,&b);

  printf("Algoritimo de Euclides: %d\n",algeuclides(a,b));
  printf("Algoritimo de Euclides Recursivo: %d\n",algeuclidesR(a,b));

  return 0;
}
