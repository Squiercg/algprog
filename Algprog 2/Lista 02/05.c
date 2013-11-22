/*Exercicio 5*/
#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
  int pot;
  float coef;
  struct cel *prox;
}celula;

/*Insere*/
void insere_lista(int pot , int coef, celula *lst , int local) {
  celula *nova, *p;

  nova = (celula *) malloc(sizeof (celula));

  if(lst->coef == 0) {
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
  lst->coef++;
}

/*Calcula a potencia*/
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
   if (lst->coef > 0) {
     for (p = lst->prox; p != NULL; p = p->prox)
       saida = saida + p->coef * potencia(x,p->pot);
   } else {
     printf("Lista vazia\n");
   }
   return saida;
}

int main(void)
{
  int n, i, a;
  float x, b;
  celula *p, *q;

  /*Lista com cabeça, esse elemento fica vaziu*/
  p = (celula *) malloc(sizeof (celula));
  p->prox = NULL;
  p->coef = 0;
  p->pot = 0;

  q = (celula *) malloc(sizeof (celula));
  q->prox = NULL;
  q->coef = 0;
  q->pot = 0;

  printf ("Entre com o número de elementos da equacao p:");
  scanf("%d",&n);

  printf("Entre com os elementos da lista p:");
  for (i= 0; i<n; i++) {
    scanf("%d",&a);
    scanf("%f",&b);
    insere_lista(a,b,p,1);
  }

  printf ("Entre com o número de elementos da equacao q:");
  scanf("%d",&n);

  printf("Entre com os elementos da lista q:");
  for (i= 0; i<n; i++) {
    scanf("%d",&a);
    scanf("%f",&b);
    insere_lista(a,b,q,1);
  }

  printf("Entre com o valor de x\n");
  scanf("%f",&x);
  printf("p=%f\n", resolve(x,p));

  printf("p=%f\n", resolve(x,q));

  printf("p=%f\n", resolve(resolve(x,q),p));

  printf("p=%f\n", resolve(x,p)+resolve(x,q));



  return 0;
}
