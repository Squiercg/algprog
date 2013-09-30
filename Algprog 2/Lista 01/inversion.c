#include <stdio.h>

#define MAX 100

int intercala(int p, int q, int r, int v[MAX])
{
   int i, j, k, w[MAX];
   int inv=0;
   i = p;
   j = q;
   k = 0;
   while (i < q && j < r) {
      if (v[i] < v[j]) {
         w[k] = v[i];
         i++;
      }
      else {
         w[k] = v[j];
         j++;
	 inv = inv + (q - i);
      }
      k++;
   }
   while (i < q) {
      w[k] = v[i];
      i++;
      k++;
   }
   while (j < r) {
      w[k] = v[j];
      j++;
      k++;
   }
   for (i = p; i < r; i++)
      v[i] = w[i-p];

   return inv;
}


/* Recebe um vetor v[p..r-1] e o rearranja em ordem crescente */
int mergesort(int p, int r, int v[MAX]) {
   int q;
   int inv=0;

   if (p < r - 1) {
      q = (p + r) / 2;
      inv  = mergesort(p, q, v);
      inv += mergesort(q, r, v);
      inv += intercala(p, q, r, v);
   }

   return inv;

}

int main(void) {

  int n, i ,vetor[MAX],inv;
 printf("Entre com o número de elementos:");

  scanf("%d",&n);

  printf("Entre com os elementos:");
  for(i=0;i<n;i++) {
    scanf("%d",&vetor[i]);
  }

  printf("Merge Sort iterativo:\n");

  inv=mergesort(0,n,vetor);

  for(i=0;i<n;i++) {
    printf("%d ",vetor[i]);
  }
  printf("\n");
  printf("Existiam %d inversoes\n",inv);

  return 0;
}
