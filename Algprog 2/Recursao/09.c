#include <stdio.h>

int potencia(int x, int n) {
  int num;

  if(n==0) {

    printf("N é %d \n",n);
    /*Se n é zero*/
    return 1;

  } else {

    if( (n%2) == 0 ) {

      printf("N é %d \n",n);
    /*Se n é par*/
      num=potencia(x,n/2);

      return num*num;


    } else {

      printf("N é %d \n",n);
    /*Se n é impar*/
      return x * potencia(x,n-1);

    }

  }

}

int main(void) {
  int num, pot;

  scanf("%d %d",&num, &pot);

  printf("Resposta: %d\n",potencia(num,pot));

  return 0;
}
