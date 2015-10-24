#include <stdio.h>

/*imprime o número n em binario*/
void imprime_alguma_coisa(int n) {

  if (n != 0) {
    imprime_alguma_coisa(n / 2);
    printf("%c", '0' + n % 2);
  }

}

int main(void)
{
  int x;

  scanf("%d",&x);

  imprime_alguma_coisa(x);

  printf("\n");

  return 0;
}
