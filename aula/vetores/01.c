#include <stdio.h>

#define MAX 100

int main(void)
{

  int i, n, A[MAX];

  printf("Informe n: ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    printf("Informe o número %d: ", i+1);
    scanf("%d", &A[i]);
  }

  printf("Números na ordem inversa da leitura:\n");

  for (i = n-1; i >= 0; i--) {
    printf("%d ", A[i]);
  }

  printf("\n");

  return 0;
}
