#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void troca(int *x , int *y);
int separa(int p, int r, int vetor[MAX]);
void quicksort(int p, int r, int vetor[MAX]);

int main(void)
{
  int i, n , teste , *vetor ,saida ;

   printf("Entre com o tamanho do vetor\n");
   scanf("%d", &n);

   vetor = (int *) malloc(n * sizeof(int));

   if (vetor != NULL) {

     printf("Entre os elementos do vetor\n");
      for (i = 0; i < n; i++)
         scanf("%d", (vetor + i));

      quicksort(0,n-1,vetor);

      teste=vetor[0]+vetor[n-1];
      i=1;

      while(i<=(n/2)) {
	if((vetor[0+i]+vetor[n-i-1])==teste) {
	  i++;
	  saida=1;
	} else {
	  i=n/2+1;
	  saida=0;
	}
      }

      if(saida==1) {
	printf("O vetor é balanceado\n");
      } else {
	printf("O vetor não é balanceado\n");
      } 

  } else {
      printf("Impossível alocar espaço\n");
   }

   return 0;
}

void troca(int *x , int *y){
  int aux;
  aux=*x;
  *x=*y;
  *y=aux;
}

int separa(int p, int r, int vetor[MAX]) {
  int x, i, j;
  x = vetor[p];
  i = p - 1;
  j = r + 1;
  while (1) {
    do {
      j--;
    } while (vetor[j] > x);
    do {
      i++;
    } while (vetor[i] < x);
    if (i < j) {
      troca(&vetor[i], &vetor[j]);
    } else {
      return j;
    }
  }
}

void quicksort(int p, int r, int vetor[MAX]) {
  int q;

  if (p < r) {
    q = separa(p, r, vetor );
    quicksort(p, q, vetor );
    quicksort(q+1, r, vetor );
  }

}
