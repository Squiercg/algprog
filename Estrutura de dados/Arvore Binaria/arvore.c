#include <stdio.h>
#include <stdlib.h>

/*Definindo o tipo arvore*/
typedef struct Arvore{
  int chave;
  struct Arvore *esquerda;
  struct Arvore *direita;
} arvore;

/*Função de inserção*/
arvore *arvore_insere (arvore* raiz, int valor) {

  if (raiz==NULL) {
    raiz = (arvore*)malloc(sizeof(arvore));
    raiz->chave = valor;
    raiz->esquerda = NULL;
    raiz->direita = NULL;
  } else {
    if (valor < raiz->chave) {
      raiz->esquerda = arvore_insere(raiz->esquerda,valor);
    } else {
      raiz->direita = arvore_insere(raiz->direita,valor);
    }
  }
  return raiz;

}

/*Função de busca*/
/*
arvore* (arvore* int v) {

  if (r == NULL)
    return NULL;
  else if (r->info > v)
    return abb_busca (r->esq, v);
  else if (r->info < v)
    return abb_busca (r->dir, v);
  else return r;
}
*/

/*Função para imprimir a arvore*/
/*Pre-ordem*/
void imprime_preordem (arvore* raiz) {
  if (raiz != NULL) {
    printf("%d ",raiz->chave);
    imprime_preordem(raiz->esquerda);
    imprime_preordem(raiz->direita);
  }
}
/*simetrica*/
void imprime_simetrica (arvore* raiz) {
  if (raiz != NULL) {
    imprime_simetrica(raiz->esquerda);
    printf("%d ",raiz->chave);
    imprime_simetrica(raiz->direita);
  }
}
/*pos-ordem*/
void imprime_posordem (arvore* raiz) {
  if (raiz != NULL) {
    imprime_posordem(raiz->esquerda);
    imprime_posordem(raiz->direita);
    printf("%d ",raiz->chave);
  }
}

int main(void) {

  int i, n;

  arvore *exemplo;

  exemplo=NULL;

  printf("Entre com o tamanho da árvore: ");
  scanf("%d",&n);

  for(i=0;i<n;i++) {
    exemplo=arvore_insere(exemplo,rand()%101);
  }

  printf("\nPre-ordem\n");
  imprime_preordem (exemplo);

  printf("\nsimetrica\n");
  imprime_simetrica (exemplo);

  printf("\npos-ordem\n");
  imprime_posordem (exemplo);


  printf("\n");
  return 0;
}
