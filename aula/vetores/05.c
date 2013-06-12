#include <stdio.h>
#define MAX 100

/* Dados dois vetores x e y, ambos com n elementos, 1 n 100,
determinar o produto escalar desses vetores.
O produto escalar entre u e v é escrito como sendo: */

int main(void)
{
  float x[MAX], y[MAX], pe;
  int i , n;

  printf("Entre com n: ");
  scanf("%d",&n);

  printf("Entre com os %d termos de x: ", n);
  for(i=0 ; i<n ; i++) {
    scanf("%f",&x[i]);
  }

  printf("Entre com os %d termos de y: ", n);
  for(i=0 ; i<n ; i++) {
    scanf("%f",&y[i]);
  }

  pe = 0;

  for(i=0 ; i<n ; i++) {
    pe = pe + (x[i] * y[i]);
  }

  printf("O produto escalar dos vetores x e y e %.2f\n",pe);

  return 0;
}


