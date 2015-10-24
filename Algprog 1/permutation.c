#include <stdio.h>

#define MAX 10

void printVector(int[], int);
void swap(int[], int, int);

int main()
{
  int v[MAX], k, i, n, r, s;

  scanf("%d", &n);

  /* Inicializa v com 0,1,2, ..., n-1 */
  for (i = 0; i < n; i++)
    v[i] = i;

  printVector(v, n);

  while (1) {
    /* Encontre o maior k tal que v[k] < v[k+1] */
    k = n - 2;
    while (k >= 0 && v[k] > v[k+1])
      k--;

    /* Se tal k nao existe, então nao temos mais permutacoes a gerar. */
    if (k == -1)
      break;

    /* Encontre o maior indice i tal que v[k] < v[i] */
    i = n - 1;
    while (v[k] > v[i])
      i--;

    /* Troque v[i] com v[k] */
    swap(v, k, i);

    /* Inverta a sequencia de v[k+1] ate v[n-1] */
    r = n - 1;
    s = k + 1;
    while (r > s) {
      swap(v, r, s);
      r--;
      s++;
    }

    printVector(v, n);
  }

  return 0;
}

void printVector(int vet[MAX], int size)
{
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", vet[i]);
  printf("\n");
}

void swap(int vet[MAX], int i, int j)
{
  int temp;

  temp = vet[i];
  vet[i] = vet[j];
  vet[j] = temp;
}
