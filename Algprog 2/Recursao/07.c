#include <stdio.h>

int piso_log2(int n){

  if(n/2==0) {
    return 0;
  } else {
    return 1+piso_log2(n/2);
  }

}

int main(void)
{
  int n;

  scanf("%d",&n);
  printf("%d\n",piso_log2(n));
  return 0;
}
