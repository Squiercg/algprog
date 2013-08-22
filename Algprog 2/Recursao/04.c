#include <stdio.h>
#define MAX 100


float soma(int n,float  v[MAX]){
  int i,sum;

  sum=0;
  for(i=0;i<n;i++){
    sum=sum+v[i];
  }

  return sum;
}


float somaR(int n,float  v[MAX]){

  int sum;

  sum=0;

  if(n==1) {
    sum=v[n-1];
  } else {
    sum=v[n-1]+somaR(n-1,v);
  }

  return sum;
}

int main(void)
{
  int n,i;
  float v[MAX];

  scanf("%d",&n);

  for(i=0;i<n;i++) {
    scanf("%f",&v[i]);
  }

  printf("Função iterativa: A soma dos elementos do vetor é %f\n",soma(n,v));
  printf("Função recursiva: A soma dos elementos do vetor é %f\n",somaR(n,v));


  return 0;
}
