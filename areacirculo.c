#include <stdio.h>

int main (void)
{
  float raio,area;
  printf("Digite o raio: \n");
  scanf("%f", &raio);
  area = 3.14159 * ( raio * raio );
  printf("A area do circulo de raio %f e %f.\n",raio,area);
  return 0;
}
