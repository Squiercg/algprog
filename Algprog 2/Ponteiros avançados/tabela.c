#include <stdio.h>
#include <math.h>

void tabela(double (*f)(double), double a, double b, double incr)
{
   int i, num_intervalos;
   double x;

   num_intervalos = ceil((b - a) / incr);

   for (i = 0; i <= num_intervalos; i++) {
      x = a + i * incr;
      printf("%3.0f %11.6f\n", x, (*f)(x)); }
}

int main(void) {
   double inicio, fim, incremento;

   printf("Informe um intervalo [a, b]: ");

   scanf("%lf%lf", &inicio, &fim);

   printf("Informe o incremento: ");

   scanf("%lf", &incremento);

   printf("Valores de coseno\n");
   tabela(cos, inicio, fim, incremento);

   printf("Valores de seno\n");
   tabela(sin, inicio, fim, incremento);

   printf("Valores de tangente\n");
   tabela(tan, inicio, fim, incremento);

   return 0;
}
