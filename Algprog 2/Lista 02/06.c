/*Exercicio 6*/
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

 if(lst->chave == 0) {
   printf("Lista vazia\n");
   return -1;
  } else {
    if(local == 0) {

      x=lst->prox->chave;
      lixo=lst->prox;
      lst->prox->ante=lst->prox;
      lst->prox=lst->prox->prox;
      free(lixo);
      lst->chave--;
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
      lst->chave--;
      return x;


    }
  }
}


/*concatenar*/
void concatenar(celula *lst1 ,celula *lst2 ,celula *saida) {
  int i, n, aux;

  n=lst1->chave;
  for(i=0;i<n;i++) {
    aux=remove_C(lst1, 0);
    insere_lista(aux,saida,1);
  }

  n=lst2->chave;
  for(i=0;i<n;i++) {
    aux=remove_C(lst2, 0);
    insere_lista(aux,saida,1);
  }

}


/*apagar lista*/
void apagalista(celula *lst){
  int i, n;

  n=lst->chave;
  for(i=0;i<n;i++) {
    remove_C(lst, 0);
  }

}

/*inverter*/

void inverte(celula *lst){
  int i, n, aux;
  celula *lstaux;

  /**/
  lstaux = (celula *) malloc(sizeof (celula));
  lstaux->prox = NULL;
  lstaux->ante = NULL;
  lstaux->chave = 0;

  n=lst->chave;

  for(i=0;i<n;i++) {
	aux=remove_C(lst, 0);
	insere_lista(aux,lstaux,1);
  }

  for(i=0;i<n;i++) {
	aux=remove_C(lstaux, 0);
	insere_lista(aux,lst,0);
  }

}



/*Remove I*/
int remove_i(celula *lst, int i) {
  int x,m;
  celula *lixo, *p;

 if(lst->chave == 0) {
   printf("Lista vazia\n");
   return -1;
 } else {

   p = lst->prox;
   for(m=0;m<(i-1);m++) {
     p = p->prox;
   }
      x=p->chave;
      lixo=p;
      p->prox->ante=p->ante;
      p->ante->prox=p->prox;
      free(lixo);
      lst->chave--;
      return x;

 }
}

/*uniao*/
int procura(int x, celula *lst) {
  int presente=0;
  celula *p;

   if (lst->chave > 0) {
     for (p = lst->prox; p != NULL && presente==0; p = p->prox){

       if(p->chave==x){
	 presente = 1;
       }


     }

   }

   return presente;
}

void uniao(celula *lst1 ,celula *lst2 ,celula *saida) {
  int i, n, aux;

  n=lst1->chave;
  for(i=0;i<n;i++) {
    aux=remove_C(lst1, 0);
    if(procura(aux,saida)==0) {
    insere_lista(aux,saida,1);
    }
  }

  n=lst2->chave;
  for(i=0;i<n;i++) {
    aux=remove_C(lst2, 0);
    if(procura(aux,saida)==0) {
      insere_lista(aux,saida,1);
    }
  }

}

int main(void)
{
  int n, i, x;
  celula *lista1, *lista2, *saida;

  /*Lista com cabeça, esse elemento fica vaziu*/
  lista1 = (celula *) malloc(sizeof (celula));
  lista1->prox = NULL;
  lista1->ante = NULL;
  lista1->chave = 0;

  lista2 = (celula *) malloc(sizeof (celula));
  lista2->prox = NULL;
  lista2->ante = NULL;
  lista2->chave = 0;

  saida = (celula *) malloc(sizeof (celula));
  saida->prox = NULL;
  saida->ante = NULL;
  saida->chave = 0;

  printf ("Entre com o número de elementos da lista 1:");
  scanf("%d",&n);

  printf("Entre com os elementos da lista 1:");
  for (i= 0; i<n; i++) {
    scanf("%d",&x);
    insere_lista(x,lista1,1);
  }

  printf("%d elementos \n",lista1->chave);
  imprime_lista(lista1);

  printf ("Entre com o número de elementos da lista 2:");
  scanf("%d",&n);

  printf("Entre com os elementos da lista 2:");
  for (i= 0; i<n; i++) {
    scanf("%d",&x);
    insere_lista(x,lista2,1);
  }

  printf("Imprimindo listas concatenada\n");
  concatenar(lista1 ,lista2 ,saida);
  imprime_lista(saida);

  printf("Invertendo lista\n");
  inverte(saida);
  imprime_lista(saida);

  printf("Retira segundo elemento\n");
  remove_i(saida,2);
  imprime_lista(saida);

  printf("Retira segundo elemento\n");
  apagalista(saida);
  imprime_lista(saida);

  printf ("Entre com o número de elementos da lista 1:");
  scanf("%d",&n);

  printf("Entre com os elementos da lista 1:");
  for (i= 0; i<n; i++) {
    scanf("%d",&x);
    insere_lista(x,lista1,1);
  }

  printf("%d elementos \n",lista1->chave);
  imprime_lista(lista1);

  printf ("Entre com o número de elementos da lista 2:");
  scanf("%d",&n);

  printf("Entre com os elementos da lista 2:");
  for (i= 0; i<n; i++) {
    scanf("%d",&x);
    insere_lista(x,lista2,1);
  }

  printf("Uniao\n");
  uniao(lista1,lista2,saida);
  imprime_lista(saida);

  return 0;
}
