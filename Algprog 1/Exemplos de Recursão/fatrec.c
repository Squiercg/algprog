#include <stdio.h>

int fatorial(int n) {
  if(n==1) {
    return 1;
  } else {
    return n*fatorial(n-1);
      }
}

int main(void) {
  int n ,fat;
  printf("Digite N!= ");
  scanf("%d",&n);

  fat=fatorial(n);

  printf("%d! = %d\n",n,fat);
  return 0;
}
