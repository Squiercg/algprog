#include <stdio.h>

int main(void)
{
  float s , pi , termo , k;

  s=1;
  pi=4;
  termo= (float) 4 / 3;
  k=1;
  while(termo >= 0.001) {
    s=-1*s;
    pi=pi+s*termo;
    k=k+2;
    termo = 4/k;
  }

  printf("%f\n",pi);

  return 0;
}
