/*Calcule o valor do polinômio p(x) = a0 + a1 x + . . . + an xn em k
pontos distintos. São dados os valores de n (grau do polinômio),
com 1 n 100, de a0 , a1 , . . . an (coeficientes reais do polinômio),
de k e dos pontos x1 , x2 , . . . , xk .*/

#include <stdio.h>

#define MAX 100

int main(void)
{
  int n , i , k , j;
  float px[MAX] = { 0 }, x[MAX] = { 0 }, pot, coef[MAX] = { 0 };

  printf("Qual o grau do polinomio?\n");
  scanf("%d",&n);

  printf("Entre com os coeficientes do polinomio\n");
  for(i=0;i<=n;i++) {
    scanf("%f",&coef[i]);
  }

  printf("Para quantos valores de x o polinomio deve ser avaliado?\n");
  scanf("%d",&k);

  printf("Entre com valor de x: \n");
  for(j=0;j<k;j++) {
    scanf("%f",&x[j]);

    px[j]=0;
    pot=1;

    for(i=0;i<=n;i++) {
      px[j]=px[j]+(pot*coef[i]);
      pot=pot*x[j];
    }
  }

  printf("\n");
  for(i=0;i<k;i++) {
    printf("P(%.2f) = %.2f\n",x[i],px[i]);
  }

    return 0;
}
