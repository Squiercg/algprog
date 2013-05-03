#include <stdio.h>

/* Esse programa recebe valor e tempo trabalhado e calcula algusn encargos fiscais*/

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

  printf("---------------------------------\n");
  printf("Salario Bruto: %f\n",a);
  printf("IR : %f\n",b);
  printf("INSS : %f\n",c);
  printf("FGTS : %f\n",d);
  printf("Total de descontos : %f\n",e);
  printf("Salário liquido : %f\n",f);

  return 0;

}
