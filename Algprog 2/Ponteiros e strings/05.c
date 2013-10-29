#include <stdio.h>
int main(void)
{
  char s[] = "Dvmuvsb", *p;
  for (p = s; *p; p++) {
    printf("%s %p  <---- %p\n", s, (void*)&s, (void*)p);
    --*p;
  }
  printf("\n\n%s\n", s);
  return 0;
}
