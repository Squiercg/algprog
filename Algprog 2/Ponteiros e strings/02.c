#include <stdio.h>

int main(void) {

  char *p = "abc";

  putchar(p);
  putchar(*p);
  printf("%s", p);
  printf("%s", *p);

  return 0;
}
