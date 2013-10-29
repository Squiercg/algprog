#include <stdio.h>

struct dois_valores {
  int vi;
  float vf;
};

int main(void) {
  struct dois_valores reg1 = {53, 7.112}, reg2, *p = &reg1;;
  reg2.vi = (*p).vf;
  reg2.vf = (*p).vi;
  printf("1: %d %f\n2: %d %f\n", reg1.vi, reg1.vf, reg2.vi, reg2.vf);
  return 0;
}
