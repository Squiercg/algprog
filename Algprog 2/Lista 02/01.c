/*
Algoritimos de Programação 2
Lista 2
Professor Marco Stefanes
Aluno Augusto Cesar de Aquino Ribas

 */

/*Exercicio 01*/
#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
  int chave;
  struct cel *prox;
}celula;

/*Imprime lista linear com cabeça*/
void imprime_lista(celula *lst) {
   celula *p;
   for (p = lst->prox; p != NULL; p = p->prox)
      printf("%d ", p->chave);
   printf("\n");
}


/*Insere um elemento*/
void insere_C(int y, celula *p) {
  celula *nova;
  nova = (celula *) malloc(sizeof (celula));
  p->chave++;
  nova->chave = y;
  nova->prox = p->prox;
  p->prox = nova;
}

/*Remove um elemento*/
int remove_C(celula *p) {
  int x;
  celula *lixo;
  x=p->prox->chave;
  lixo = p->prox;
  p->prox = lixo->prox;
  free(lixo);
  return x;
}


int main(void)
{
  int n, i, x;
  celula *lista;

  /*Lista com cabeça*/
  lista = (celula *) malloc(sizeof (celula));
  lista->prox = NULL;
  lista->chave = 0;

  printf ("Entre com o número de elementos:");
  scanf("%d",&n);

  printf("Entre com os elementos:");
  for (i= 0; i<n; i++) {
    scanf("%d",&x);
    insere_C(x,lista);
  }

  imprime_lista(lista);

  x=remove_C(lista);
  printf("\n%d\n",x);

  return 0;
}
