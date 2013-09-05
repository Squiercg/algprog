#include <stdio.h>
#define MAX 100

int busca_binaria_registro(int n, int v[MAX], int x) {
  int esq, dir, meio;
  esq = -1;
  dir = n;
  while (esq < dir - 1) {

    meio = (esq + dir) / 2;

    if (v[meio] < x) {
      esq = meio;
    } else {
      dir = meio;
    }

  }

return dir;
}

int main(void) {



  return 0;
}
