#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
  int chave;
  struct cel *prox;
  struct cel *ante;

}celula;

/*Imprime lista linear com cabeça*/
void imprime_lista(celula *lst) {
   celula *p;
   if (lst->chave > 0) {
     for (p = lst->prox; p != NULL; p = p->prox)
       printf("%d ", p->chave);
     printf("\n");
   } else {
     printf("Lista vazia\n");
   }
}


/*Insere*/
void insere_lista(int y, celula *lst , int local) {
  celula *nova, *p;

  nova = (celula *) malloc(sizeof (celula));

  if(lst->chave == 0) {
    nova->chave = y;
    lst->prox=nova;
    nova->prox=NULL;
    nova->ante=NULL;
  } else {
    if(local == 0) {

      nova->chave = y;
      nova->prox=lst->prox;
      lst->prox->ante=nova;
      lst->prox=nova;
      nova->ante=NULL;

    } else {

      p = lst->prox;
      while(p->prox != NULL) {
	p = p->prox;
    }
      nova->chave = y;
      nova->prox=NULL;
      p->prox=nova;
      nova->ante=p;

    }
  }
  lst->chave++;
}


/*Remove*/
int remove_C(celula *lst, int local) {
  int x;
  celula *lixo, *p;
  lst->chave--;

 if(lst->chave == 0) {
   printf("Lista vazia\n");
   return 0;
  } else {
    if(local == 0) {

      x=lst->prox->chave;
      lixo=lst->prox;
      lst->prox=lst->prox->prox;
      lst->prox->ante=NULL;
      free(lixo);
      return x;

    } else {

      p = lst->prox;
      while(p->prox->prox != NULL) {
	p = p->prox;
    }
      x=p->chave;
      lixo=p->prox;
      p->prox=NULL;
      free(lixo);
      return x;

    }
  }
}

int main(void)
{
  int n, i, x;
  celula *lista;

  /*Lista com cabeça, esse elemento fica vaziu*/
  lista = (celula *) malloc(sizeof (celula));
  lista->prox = NULL;
  lista->ante = NULL;
  lista->chave = 0;

  printf ("Entre com o número de elementos:");
  scanf("%d",&n);

  printf("Entre com os elementos:");
  for (i= 0; i<n; i++) {
    scanf("%d",&x);
    insere_lista(x,lista,0);
  }

  printf("%d elementos \n",lista->chave);
  imprime_lista(lista);

  printf ("Entre com o número de elementos:");
  scanf("%d",&n);

  printf("Entre com os elementos:");
  for (i= 0; i<n; i++) {
    scanf("%d",&x);
    insere_lista(x,lista,1);
  }

  printf("%d elementos \n",lista->chave);
  imprime_lista(lista);


  printf("Remove o primeiro elemento:");

  remove_C(lista, 0);
  printf("%d elementos \n",lista->chave);
  imprime_lista(lista);

  printf("Remove o ultimo elemento:");

  remove_C(lista, 1);
  printf("%d elementos \n",lista->chave);
  imprime_lista(lista);

  return 0;
}
