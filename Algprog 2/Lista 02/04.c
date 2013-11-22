#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
  int chave;
  struct cel *prox;
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
   } else {
    if(local == 0) {

      nova->chave = y;
      nova->prox=lst->prox;
       lst->prox=nova;

    } else {

      p = lst->prox;
      while(p->prox != NULL) {
	p = p->prox;
    }
      nova->chave = y;
      nova->prox=NULL;
      p->prox=nova;
 
    }
  }
  lst->chave++;
}


/*Remove*/
int remove_C(celula *lst, int local) {
  int x;
  celula *lixo, *p;

 if(lst->chave == 0) {
   printf("Lista vazia\n");
   return -1;
  } else {
    if(local == 0 || lst->chave == 1) {

      x=lst->prox->chave;
      lixo=lst->prox;
      lst->prox=lst->prox->prox;
      free(lixo);
      lst->chave--;
      return x;

    } else {

      p = lst->prox;
      while(p->prox->prox != NULL) {
	p = p->prox;
    }
      x=p->prox->chave;
      lixo=p->prox;
      p->prox=NULL;
      free(lixo);
      lst->chave--;
      return x;

    }
  }
}

int main(void)
{
  int n, i, x, a , b;
  celula *l, *r;

  /*Lista com cabeça, esse elemento fica vaziu*/
  l = (celula *) malloc(sizeof (celula));
  l->prox = NULL;
  l->chave = 0;

  r = (celula *) malloc(sizeof (celula));
  r->prox = NULL;
  r->chave = 0;

  printf ("Entre com o número de elementos da lista l:");
  scanf("%d",&n);

  printf("Entre com os elementos da lista l:");
  for (i= 0; i<n; i++) {
    scanf("%d",&x);
    insere_lista(x,l,1);
  }

  printf("%d elementos \n",l->chave);
  imprime_lista(l);

  n=l->chave/2;
  for(i=0;i<n;i++){

    a=remove_C(l, 0);
    b=remove_C(l, 1);
    printf("a=%d B=%d\n",a,b);
    insere_lista(a+b,r,1);

  }

  printf("%d elementos \n",r->chave);
  imprime_lista(r);


  return 0;
}
