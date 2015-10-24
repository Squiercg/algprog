#include <stdio.h>
struct apts {
  char *c;
  int *i;
  float *f;
};

int main(void) {
  char caractere;
  int inteiro;
  float real;
  struct apts reg;
  reg.c = &caractere;
  reg.i = &inteiro;
  reg.f = &real;
  printf("Entre com um caracter, um inteiro e um float:");
  scanf("%c%d%f", reg.c, reg.i, reg.f);
  printf("%c\n%d\n%f\n", caractere, inteiro, real);
  return 0;
}
