#include <stdio.h>

int Fib(int i){

  if(i==1) {
    return 1;
  } else {
    if(i==2) {
      return 1;
    } else {
      return Fib(i-1)+Fib(i-2);
    }
  }
}

int main(void) {
  int i,k,j;

  scanf("%d",&k);

  for(j=1;j<=k;j++) {
    scanf("%d",&i);
    printf("%d\n",Fib(i));
  }

      return 0;
}
