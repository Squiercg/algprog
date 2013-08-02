#include <stdio.h>

int main(void)

{
  char aux[100];

  scanf("%[^\n]",aux);

  printf("----------------------");
  printf("%s",aux);

  return 0;
}
