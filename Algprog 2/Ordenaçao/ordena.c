#define MAX 100

void insertionsortR(int vetor[MAX], int n) {
  int i, aux;

  if(n>1) {
    insertionsortR(vetor,n-1);
    aux=vetor[n-1];
    i=n-1;
    while(vetor[i-1]>aux && i>=0 ) {
      vetor[i]=vetor[i-1];
      i--;
     }
    vetor[i]=aux;
  }
}

void selectionsortR(int vetor[MAX],int n){
  int max,imax,j;

  if(n>1){
    max=vetor[0];
    imax=0;

    for(j=0;j<n;j++) {
      if(vetor[j]>max){
	max=vetor[j];
	imax=j;
      }

    }
      vetor[imax]=vetor[n-1];
      vetor[n-1]=max;

      selectionsortR(vetor,n-1);
  }

}

void intercala(int p, int q, int r, int v[MAX])
{
   int i, j, k, w[MAX];

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
