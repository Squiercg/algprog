#include <stdio.h>

#define MAX 100

/*
(a) A função maximo acima resolve o problema?
Sim
(b) Faz sentido trocar x = v[0] por x = 0 ?
Não, ja que a função não conseguira dar a resposta certa caso contenha números negativos
(c) Faz sentido trocar x = v[0] por x = INT_MIN 1 ?
Sim
(d) Faz sentido trocar x < v[i] por x <= v[i] ?
Se essa troca for feita, sempre havera uma atrivuição no caso dos números iguais, o que não é necessario ja que 
a resposta será a mesma.
*/

int maximo(int n, int v[MAX])
{
  int i, x;
  x = v[0];
  for (i = 1; i < n; i++)
    if (x < v[i])
      x = v[i];

  return x;
}

int main(void)
{
 int n, i, vetor[MAX+1];

 scanf("%d",&n);

  for(i=0;i<n;i++) {
    scanf("%d",&vetor[i]);
  }

  printf("O valor maximo do vetor é %d\n",maximo(n,vetor));

  return 0;
}
