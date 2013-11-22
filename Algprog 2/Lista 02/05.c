#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
  int pot;
  int coef;
  struct cel *prox;
}celula;




/*Insere*/
void insere_lista(int pot , int coef, celula *lst , int local) {
  celula *nova, *p;

  nova = (celula *) malloc(sizeof (celula));

  if(lst->chave == 0) {
    nova->pot = pot;
    nova->coef = coef;
    lst->prox=nova;
    nova->prox=NULL;
   } else {
    if(local == 0) {

      nova->pot = pot;
      nova->coef = coef;
      nova->prox=lst->prox;
      lst->prox=nova;

    } else {

      p = lst->prox;
      while(p->prox != NULL) {
	p = p->prox;
    }
      nova->pot = pot;
      nova->coef = coef;
      nova->prox=NULL;
      p->prox=nova;
 
    }
  }
  lst->chave++;
}

float potencia(float x, int n) {
  float num;
  if(n==0) {
    printf("N é %d \n",n);
     return 1;
  } else {
    if( (n%2) == 0 ) {
      num=potencia(x,n/2);
      return num*num;
    } else {
      return x * potencia(x,n-1);
    }
  }
}



/*Imprime lista linear com cabeça*/
float resolve(float x ,celula *lst) {
  float saida=0;
  celula *p;
   if (lst->chave > 0) {
     for (p = lst->prox; p != NULL; p = p->prox)
       saida = saida + p->coef * potencia(x,p->pot);
   } else {
     printf("Lista vazia\n");
   }
   return saida;
}

int main(void)
{
  int n, i, x, a , b;
  celula *p, *q;

  /*Lista com cabeça, esse elemento fica vaziu*/
  p = (celula *) malloc(sizeof (celula));
  p->prox = NULL;
  p->coef = 0;
  p->pot = 0;

  r = (celula *) malloc(sizeof (celula));
  r->prox = NULL;
  r->coef = 0;
  r->pot = 0;

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
