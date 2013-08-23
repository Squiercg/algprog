#include <stdio.h>

int ciclo(int n){
  int ciclo=1;

  while(n!=1) {

    if(n%2==0) {
      printf("%d ",n/2);
      n=n/2;
    } else {
      printf("%d ",n*3+1);
      n=n*3+1;
    }

    ciclo++;
  }
  return ciclo;
}

int cic=1;

int cicloR(int n){
  cic++;

  if(n%2==0) {
    printf("%d ",n/2);
    n=n/2;
  } else {
    printf("%d ",n*3+1);
    n= n*3+1;
  }
 
  if(n==1) {
    return 0;
  } else {
    cicloR(n);
    return cic;
  }

}

int main(void)
{
  int x, saida;
  scanf("%d",&x);

  saida=ciclo(x);
  printf("\niterativo %d\n",saida);
  saida=cicloR(x);
  printf("\nrecursivo %d\n",saida);

  return 0;
}
