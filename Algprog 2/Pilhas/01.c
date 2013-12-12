#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
  int conteudo;
  struct cel *prox;
} celula;

/* Recebe um elemento y e uma pilha t e insere y no topo de t */
void empilha_enc_C(int y, celula *t) {
  celula *nova;
  nova = (celula *) malloc(sizeof (celula));
  nova->conteudo = y;
  nova->prox = t->prox;
  t->prox = nova;
}

/* Recebe uma pilha t e remove um elemento de seu topo */
int desempilha_enc_C(celula *t) {
  int x;
  celula *p;
  if (t->prox != NULL) {
    p = t->prox;
    x = p->conteudo;
    t->prox = p->prox;
    free(p);
    return x;
  } else {
    printf("Pilha vazia!\n");
    return -1;
  }
}

int main(void)
{
  int aux,i,n;
  celula *t;

  t = NULL;

  printf("Entre com o tamanho da pilha\n");

  scanf("%d",&n);

  for(i=0;i<n;i++) {
    aux=rand()%100;
    printf("Adicionando %d\n",aux);
    empilha_enc_C(aux,t);
  }

  printf("\n Fim do empilhamento \n");
  aux=desempilha_enc_C(t);

  while(aux!=-1) {
    printf("%d,",aux);
    aux=desempilha_enc_C(t);
  }
  printf("\n");

  return 0;
}
