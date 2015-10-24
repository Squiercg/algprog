#include <stdio.h>
#include <stdlib.h>

struct cel {
   int chave;
   struct cel *prox;
};

typedef struct cel celula;

/*Imprime lista linear*/
void imprime_lista(celula *lst)
{
   celula *p;
   for (p = lst; p != NULL; p = p->prox)
      printf("%d ", p->chave);
   printf("\n");
}

/*Busca iterativa em lista linear*/
celula *busca_C(int x, celula *lst)
{
  celula *p;
  p = lst->prox;
  while (p != NULL && p->chave != x)
    p = p->prox;
  return p;
}

/*Busca recursiva em lista linear*/
celula *buscaR_C(int x, celula *lst)
{
   if (lst->prox == NULL)
      return NULL;
   if (lst->prox->chave == x)
      return lst->prox;
   return buscaR_C(x, lst->prox);
}

/*Remove um elemento da lista linear*/
void remove_C(celula *p)
{
   celula *lixo;
   lixo = p->prox;
   p->prox = lixo->prox;
   free(lixo);
}


int main(void) {
  int n, i, x;
  celula *lista, *aux, *proximo;

  /*Lista com cabeça, esse elemento fica vaziu*/
  lista = (celula *) malloc(sizeof (celula));
  lista->prox = NULL;

  /*Como não podemos mais mexer na variavel lista, copiamos o endereço dela*/
  proximo=lista;

  printf ("Entre com o número de elementos:");
  scanf("%d",&n);

  printf("Entre com os elementos:");
  for (i= 0; i<n; i++) {
    /*Pegando o endereço anterior*/
    aux=proximo;

    /*Criando um novo elemento*/
    proximo = (celula *) malloc(sizeof (celula));
    if(proximo==NULL)
      printf("Cabou a memoria no elemento %d \n",i+1);

    /*Salvando uma chave no novo elemento*/
    scanf("%d",&proximo->chave);

    /*Apontando esse novo elemento para NULL*/
    proximo->prox = NULL;

    /*Apontando o endereço anterior para este endereço*/
    aux->prox=proximo;
  }

  /*Imprimindo lista*/
  imprime_lista(lista->prox);

  /*Busca iterativa*/
  printf("Entre com um inteiro para buscar iterativamente na lista linear:");
  scanf("%d",&x);

  aux=busca_C(x,lista);

  if(aux==NULL)
    printf("%d não está na lista linear\n",x);
  else
    printf("%d está no endereço %p\n",(*aux).chave,(void*)&aux);

  /*Busca recursiva*/
  printf("Entre com um inteiro para buscar recursivamente na lista linear:");
  scanf("%d",&x);

  aux=buscaR_C(x,lista->prox);

  if(aux==NULL)
    printf("%d não está na lista linear\n",x);
  else
    printf("%d está no endereço %p\n",aux->chave,(void*)&aux);

  /*Remoção*/
  printf("Qual elemento entre 1 e %d deseja remover?",n);
  scanf("%d",&x);

  aux=lista->prox;

  for(i=1;i<(x-1);i++){
    aux=aux->prox;
  }

  remove_C(aux);

  /*Conferindo remoção*/
  imprime_lista(lista->prox);



  return 0;
}
