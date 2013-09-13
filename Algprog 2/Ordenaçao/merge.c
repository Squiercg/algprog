#include <stdio.h>

#define MAX 100

/* Recebe os vetores crescentes v[p..q-1] e v[q..r-1]
   e rearranja v[p..r-1] em ordem crescente */
void intercala(int p, int q, int r, int v[MAX])
{
   int i, j, k, w[MAX];

  for(i=p;i<q;i++)
     printf("%d ",v[i]);
   printf("   ");
   for(i=q;i<r;i++)
     printf("%d ",v[i]);
   printf("\n");


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
}


/* Recebe um vetor v[p..r-1] e o rearranja em ordem crescente */
void mergesort(int p, int r, int v[MAX])
{
   int q;
   if (p < r - 1) {
      q = (p + r) / 2;
      mergesort(p, q, v);
      mergesort(q, r, v);
      intercala(p, q, r, v);
   }
}




int main(void) {

 int n, i ,vetor[MAX];

  scanf("%d",&n);

  for(i=0;i<n;i++) {
    scanf("%d",&vetor[i]);
  }

  printf("Merge Sort iterativo:\n");

  mergesort(0,n,vetor);

  for(i=0;i<n;i++) {
    printf("%d ",vetor[i]);
  }
  printf("\n");

  return 0;
}
