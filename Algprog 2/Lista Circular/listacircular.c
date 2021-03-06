#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
  int chave;
  struct cel *prox;
} celula;


/*Imprime lista circular*/
void imprime_lista(celula *lista) {
   celula *p;
   p=lista;
   if(lista->prox==lista) {
     printf("Lista vazia");
   } else {
     do {
       p = p->prox;
       printf("%d ", p->chave);
     }while (p->prox != lista);
   }
   printf("\n");
}

/* Recebe uma chave x e uma lista linear circular c e verifica se x consta em
c, devolvendo a célula em que x se encontra ou NULL em caso contrário */
celula *busca_circular(int x, celula *c) {
  celula *p, *q;
  p = c;
  p->chave = x;
  q = c->prox;
  while (q->chave != x)
    q = q->prox;
  if (q != c)
    return q;
  else
    return NULL;
}

/* Recebe uma chave y e uma lista circular c e insere y no início da lista c */
void insere_circular(int y, celula *c) {
  celula *nova;
  nova = (celula *) malloc(sizeof (celula));
  nova->chave = y;
  nova->prox = c->prox;
  c->prox = nova;
}

/* Recebe uma chave x e uma lista linear circular c e
remove a célula com chave x da lista c, caso exista */
void remove_circular(int x, celula *c) {
  celula *p, *q;
  p = c;
  p->chave = x;
  q = p->prox;
  while (q->chave != x) {
    p = q;
    q = q->prox;
  }
  if (q != c) {
    p->prox = q->prox;
    free(q);
  }
}

int main(void){
  int n, i, x;

  celula c, *lista , *aux;
  c.prox = &c;
  lista = &c;

/* Possibilidades:

  celula *lista;
  lista = (celula *) malloc(sizeof (celula));
  lista->prox = lista;

  celula *lista;
  lista = NULL; 
*/

  printf("Lista circular com cabeça.\n");

  printf("Entre com o número de elementos:");
  scanf("%d",&n);

  printf("Antes:");
  imprime_lista(lista);

  for(i=0;i<n;i++){
    scanf("%d",&x);
    insere_circular(x,lista);
  }

  printf("Depois:");
  imprime_lista(lista);

 printf("Entre com um elemento para procurar na lista:");

  scanf("%d",&x);
  aux=busca_circular(x,lista);

  if(aux==NULL) {
    printf("%d não encontrado\n", x);
  } else {
    printf("Endereço %p contem %d\n",(void*)aux->prox, aux->chave);
  }


 printf("Entre com um elemento para remover:");
 scanf("%d",&x);

  printf("Antes da remoção :");
  imprime_lista(lista);

 remove_circular(x,lista);

  printf("Depois da remoção :");
  imprime_lista(lista);

 return 0;
}
