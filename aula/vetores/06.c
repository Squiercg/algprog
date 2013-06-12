/*Calcule o valor do polinômio p(x) = a0 + a1 x + . . . + an xn em k
pontos distintos. São dados os valores de n (grau do polinômio),
com 1 n 100, de a0 , a1 , . . . an (coeficientes reais do polinômio),
de k e dos pontos x1 , x2 , . . . , xk .*/

#include <stdio.h>

#define MAX 100

int main(void)
{
  int n , i , k , j;
  float px, x, pot, coef[MAX] = { 0 };

  printf("Qual o grau do polinomio?\n");
  scanf("%d",&n);

  printf("Entre com os coeficientes do polinomio\n");
  for(i=0;i<=n;i++) {
    scanf("%f",&coef[i]);
  }

  printf("Para quantos valores de x o polinomio deve ser avaliado?\n");
  scanf("%d",&k);

  for(j=1;j<=k;j++) {
    printf("Entre com valor de x: ");
    scanf("%f",&x);

    px=0;
    pot=1;

    for(i=0;i<=n;


  }





}
