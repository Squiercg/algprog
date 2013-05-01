#include <stdio.h>

int main(void)
{
  float hora , valor , a , b , c , d , e , f;

  printf("Entre com quantas horas você trabalha e o valor da hora trabalhada: ");
  scanf("%f %f", &hora , &valor );

  a = hora * valor;
  if(a>2500)
    b=0.2*a;
 else
   if(a>1500)
     b=0.1*a;
   else
     if(a>900)
       b=0.05*a;
     else
       b=0;

  c = a * 0.1;
  d = a * 0.11;
  e = b + c;
  f = a - e;

  printf("Salario Bruto: %d\n",a);
  printf("IR : %d\n",b);
  printf("INSS : %d\n",c);
  printf("FGTS : %d\n",d);
  printf("Total de descontos : %d\n",e);
  printf("Salário liquido : %d\n",f);





}
