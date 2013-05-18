#include <stdio.h>

int main(void) {
  int n , i ,fat;
  printf("Digite N!= ");
  scanf("%d",&n);

  fat=1;

  for(i=1;i<=n;i++) {
    fat=fat*i;
  }

  printf("%d! = %d\n",n,fat);
  return 0;
}
