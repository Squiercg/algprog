#include <stdio.h>
#include <string.h>

char *duplica(const char *p) {
  char *q;
  strcpy(q, p);
  return q;
}

int main(void) {
  char cadeia[6]={"teste"}, *copia;

  copia=duplica(cadeia);

  printf("%s\n",copia);

  return 0;
}
