#include<stdio.h>
#define MAX 100


/*Tempo de execução é N^2*/
float polinomio(int grau, float coef[], float x) {
  int i,j;
  float out=0, pot;

  for(i=0;i<=grau;i++){
    pot=1;
    for(j=1;j<=i;j++){
      pot=pot*x;
    }
    out=out+(coef[i]*(pot));
  }

  return out;
}

/*Tempo de execução é N*/
float horner(int grau, float coef[], float x) {
  int i;
  float out=0;

  for(i=grau;i>0;i--) {
    out=(out+coef[i])*x;
  }

  out=out+coef[0];
  return out;
}


int main(void)
{
  int i, grau;
  float coef[MAX],x;

  printf("Entre com o grau do polinomio:");
  scanf("%d",&grau);

  printf("Entre com os coeficientes (do maior para o menor grau):");
  for(i=grau;i>=0;i--){
    scanf("%f",&coef[i]);
  }

  printf("Entre com o valor a ser avaliado:");
  scanf("%f",&x);

  printf("Metodo convencional: f(%f) = %f\n",x,polinomio(grau,coef,x));
  printf("Metodo Horner: f(%f) = %f\n",x,horner(grau,coef,x));

  return 0;
}
