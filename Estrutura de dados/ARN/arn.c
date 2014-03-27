#include <stdio.h>
#include<stdlib.h>

#define BLACK 0
#define RED 1

struct No
{
   int cor;
   int info;
   struct No* esq;
   struct No* dir;
   struct No* pai;
};
typedef struct No Node;

Node* avo(Node *n);

Node* tio(Node *n);

Node* raiz(Node* a);

Node* antecessor(Node* a);

int calculaNosNegros(Node* a);

void imprimePre(Node* a);

int alturaNegra(Node* a);

Node* rotacao_dir(Node* K2);

Node* rotacao_esq(Node *K1);

Node* insere(Node* a, int v, Node* pai);

void insercao_caso1(Node* n);

void insercao_caso2(Node* n);

void insercao_caso3(Node* n);

void insercao_caso4(Node* n);

void insercao_caso5(Node* n);

Node* avo(Node *n){
    if((n != NULL) && (n->pai != NULL)) 
        return n->pai->pai;
    else
        return NULL;
}


Node* tio(Node *n){
  Node* a;
  a=avo(n);

  if(a != NULL) {
    if(n->pai == a->esq) {
      return a->dir;
    } else {
      return a->esq;
    }
  } else {
    return NULL;
  }

}


void imprimePre(Node* a){
  if (a != NULL) {
    printf("%d-%d ",a->info,a->cor);
    imprimePre(a->esq);
    imprimePre(a->dir);
  }
}


int alturaNegra(Node* a){


  if (a == NULL) {
    return 1;
  } else {
    if(a->esq!=NULL && a->cor==1) {
      return 1+alturaNegra(a->esq);
    } else {
      if(a->dir!=NULL && a->cor==1) {
	  return 1+alturaNegra(a->dir);
	} else {
	  if(a->esq!=NULL && a->cor==0) {
	    return 0+alturaNegra(a->esq);
	  } else {
	    return 0+alturaNegra(a->dir);
	  }
      }
    }
  }
}

int calculaNosNegros(Node* a){

  if (a != NULL && a->cor==0) {    
    return 1+calculaNosNegros(a->esq);
    return 1+calculaNosNegros(a->dir);
  } else {
    if (a != NULL && a->cor==1) {
      return 0+calculaNosNegros(a->esq);
      return 0+calculaNosNegros(a->dir);
    } else {
      return 0;
    }
  }

}


Node* antecessor(Node* a){
  Node* caminho;

  if(a->esq==NULL) {
    printf("Não tem antecessor\n");
    return a;
  } else {
    caminho=a->esq;

    while(caminho->dir!=NULL) {
      caminho=caminho->dir;
    }
  }

  return caminho;

}


Node* raiz(Node* a){

if(a->pai==NULL)
    return a;
else
	return raiz(a->pai);
}

Node* rotacao_dir(Node* K2)
{

   Node *K1;

    K1 = K2->esq;
    K2->esq = K1->dir;
    K1->dir = K2;
     
    K1->pai = K2->pai;
    K2->pai = K1;
    
    if (K2->esq != NULL) {
        K2->esq->pai = K2;
    }

    if(K1->pai != NULL){
        if(K1->info < K1->pai->info)
            K1->pai->esq = K1;
        else
            K1->pai->dir = K1;
	}

   return K1;

}

Node* rotacao_esq(Node *K1)
{
   Node *K2;

   K2 = K1->dir;

   K1->dir = K2->esq;
   K2->esq = K1;
    K2->pai = K1->pai;
    K1->pai = K2;
    if (K1->dir != NULL) {
        K1->dir->pai = K1;
    }

    if(K2->pai != NULL){
        if(K2->info < K2->pai->info)
            K2->pai->esq = K2;
        else
            K2->pai->dir = K2;
}
    
   return K2;

}

Node* insere(Node* a, int v, Node* pai){
    Node* aux;
    
    if(a==NULL){
        a= (Node*)malloc(sizeof(Node));
        a->info = v;
        a->esq=a->dir=NULL;
        a->pai = pai;
        a->cor = RED;
        
        if (pai != NULL) {
            if (v < a->pai->info) {
                pai->esq = a;
            }
            else{
                pai->dir = a;
            }
        }    
        insercao_caso1(a);
    }
    else 
        if(v< a->info){
            aux = insere(a->esq, v, a);
        }
        else{
            aux = insere(a->dir, v, a);
        }
        
    a = raiz(a);
    
    return a;
}

void insercao_caso1(Node* n){

    if(n->pai == NULL)
        n->cor = BLACK;
    else
        insercao_caso2(n);    
}

void insercao_caso2(Node* n){
    
    if(n->pai->cor == BLACK)
        return;
    else
        insercao_caso3(n);
}

void insercao_caso3(Node* n){
    Node *t = tio(n), *a;
    
    if((t != NULL) &&(t->cor == RED)){
        n->pai->cor = BLACK;
        t->cor = BLACK;
        a = avo(n);
        a->cor = RED;
        insercao_caso1(a);
    }
    else{
        insercao_caso4(n);
    }
}

void insercao_caso4(Node *n){
    Node *a = avo(n), *p = n->pai;
    
    if(n == p->dir && p == a->esq){
        p = rotacao_esq(p);
        n = n->esq;

    }else 
        if(n == p->esq && p == a->dir){
            p = rotacao_dir(p);
            n = n->dir;

    }
    insercao_caso5(n);
}

void insercao_caso5(Node* n){
    Node *a = avo(n);
    n->pai->cor = BLACK;
    a->cor = RED;
    
    if(n == n->pai->esq){
        a = rotacao_dir(a);
	}
    else{
        a = rotacao_esq(a);
    }
    

}



int main(void)
{

  int i, n;

  Node *exemplo;

  exemplo=NULL;

  printf("Entre com o tamanho da árvore: ");
  scanf("%d",&n);

  for(i=0;i<n;i++) {
    exemplo=insere(exemplo,rand()%101,NULL);
  }

  imprimePre(exemplo);
  printf("\n");

  printf("Altura: %d\n",alturaNegra(exemplo));

  printf("Nos Negros: %d\n",calculaNosNegros(exemplo));

  printf("Antecessor: %d\n",antecessor(exemplo)->info);

   return 0;
}
