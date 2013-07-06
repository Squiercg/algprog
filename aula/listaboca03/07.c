#include <stdio.h>

int MENORES(int x, int V[], int n){
  int cont=0, i;

  for(i=0;i<n;i++) {

    if(V[i]<=x) {
      cont++;
    }
  }

  return cont;
}

int main(void)
{

  int n , x , i, vetor[100];

  scanf("%d",&n);

  for(i=0;i<n;i++){
  scanf("%d",&vetor[i]);
  }

  scanf("%d",&x);

  printf("%d\n", MENORES(x,vetor,n));

  return 0;
}
