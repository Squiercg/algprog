#include <stdio.h>

/* Recebe dois números inteiros esq e dir, um vetor de números
inteiros crescente v[esq..dir] e um número inteiro x tais
que v[esq] < x <= v[dir] e devolve um índice k em
[esq+1, dir] tal que v[k-1] < x <= v[k] */

int busca_binaria_R(int esq, int dir, int v[MAX], int x) {
  int meio;
  if (esq == dir - 1)
    return dir;
  else {
    meio = (esq + dir) / 2;
    if (v[meio] < x) {
      return busca_binaria_R(meio, dir, v, x);
    } else {
      return busca_binaria_R(esq, meio, v, x);
    }
  }
}

int main(void) {


  return 0;
}



