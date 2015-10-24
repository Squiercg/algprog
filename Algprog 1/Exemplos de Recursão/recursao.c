#include <stdio.h>

int recursao(int n) {
  printf("Entrando na função Recursão para n=%d\n",n);
    if(n==0) {
      printf("Caso Base, n = %d\n",n);
	}
    else {
      printf("Chamando funçao recursão(n-1), para n=%d e (n-1)=%d\n",n,n-1);
      recursao(n-1);
	  }

    printf("Saindo da funçao de recursão de %d\n",n);
    return 0;
}



int main(void) {

  int n;

  printf("Entre com um número: ");

  scanf("%d",&n);

  recursao(n);

  return 0;

}
