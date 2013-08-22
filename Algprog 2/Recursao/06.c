#include <stdio.h>

int fib(int i){

  if(i==1) {
    return 1;
  } else {
    if(i==2) {
      return 1;
    } else {
      return fib(i-1)+fib(i-2);
    }
  }

}

int main(void)
{
  int i;

  scanf("%d",&i);

  printf("Resultado = %d\n",fib(i));

  return 0;
}
