/*Exercicio 7*/
#include<stdio.h>
#define MAX 10

void enfileira(int *i, int *f, int F[], int x) {
  if (*f != *i || *f == -1) {
    if (*f == -1) {
      *i = 0;
      *f = 0;
    }
    F[*f] = x;
    (*f)++;
    if (*f == MAX)
      *f = 0;
  } else {
    printf("Fila cheia!\n");
  }
}

int desenfileira(int *i, int *f, int F[]) {
  int r;
  r = -1;
  if (*i != -1) {
    r = F[*i];
    if (*i != *f)
      *i = (*i + 1) % MAX;
    else {
      *i = -1;
      *f = -1;
    }
  } else {
    printf("Fila vazia!\n");
  }
  return r;
}

int main(void) {

  int m, i, f, F[MAX];
  i = -1;
  f = -1;

  enfileira(&i, &f, F, 2);
  enfileira(&i, &f, F, 3);
  enfileira(&i, &f, F, 4);

  printf("%d %d\n",i,f);

  for(m=i;m!=f;m=(m+1)%MAX){
    printf("%d ",F[m]);
  }
  printf("\n");


  desenfileira(&i, &f, F);
  desenfileira(&i, &f, F);

  printf("%d %d\n",i,f);

  for(m=i;m!=f;m=(m+1)%MAX){
    printf("%d ",F[m]);
  }
  printf("\n");


  return 0;
}
