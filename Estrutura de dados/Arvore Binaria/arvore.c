#include <stdio.h>
#include <stdlib.h>

/*Definindo o tipo arvore*/
typedef struct Arvore{
  int chave;
  struct Arvore *esquerda;
  struct Arvore *direita;
} arvore;

//void imprime_arvore(arvore *raiz, int altura) {
//}


/*
 *
 *Funções primaria de arvore primaria
 *
 **/

/*Função de inserção*/
arvore* arvore_insere(arvore* raiz, int valor);
/*Função de remoçao*/
arvore* arvore_remove(arvore* raiz, int valor);
/*Função de busca*/
arvore* busca_arvore(arvore* raiz, int n);

/*Função para imprimir a arvore*/
/*Pre-ordem*/
void imprime_preordem (arvore* raiz);
/*simetrica*/
void imprime_simetrica (arvore* raiz);
/*pos-ordem*/
void imprime_posordem (arvore* raiz);

/*
 *
 *Funções para arvore avl
 *
 **/

int altura(arvore* raiz) {

  int iEsq,iDir;

  if (raiz == NULL) {
    return 0;
  }

  iEsq = altura(raiz->esquerda);
  iDir = altura(raiz->direita);

  if ( iEsq > iDir ) {
    return iEsq + 1;
  } else {
    return iDir + 1;
  }

}


int main(void) {

  int i, n,x;

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
  printf("Entre com um numero para buscar na arvore: ");
  scanf("%d",&x);

  printf("Pondeiro: %p\n",(void*)busca_arvore(exemplo,x));

  printf("Entre com um numero remover da arvore na arvore: ");
  scanf("%d",&x);

  printf("\nAntes da remoção\n");
  imprime_simetrica (exemplo);

  arvore_remove(exemplo,x);

  printf("\nDepois da remoção\n");
  imprime_simetrica (exemplo);

  printf("\n");

  printf("A altura atual dessa arvore é %d\n",altura(exemplo));


  //  print_tree(exemplo, altura(exemplo));



  printf("\n");
  return 0;
}


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

/*Função de remoçao*/
arvore* arvore_remove (arvore* raiz, int valor) {

  if (raiz == NULL) {
    return NULL;
  } else {
    if (raiz->chave > valor) {
      raiz->esquerda = arvore_remove(raiz->esquerda, valor);
    } else {
      if (raiz->chave < valor) {
	raiz->direita = arvore_remove(raiz->direita, valor);
      }	else {

/* Achamos o nó a remover*/
/* Nó sem filhos */
	if (raiz->esquerda == NULL && raiz->direita == NULL) {
	  free (raiz);
	  raiz = NULL;
	} else {

/* nó só tem filho à direita */
	  if (raiz->esquerda == NULL) {
	    arvore* temporario = raiz;
	    raiz = raiz->direita;
	    free (temporario);
	  } else {
/* só tem filho à esquerda */
	    if (raiz->direita == NULL) {
	      arvore* temporario = raiz;
	      raiz = raiz->esquerda;
	      free (temporario);
	    } else {
/* nó tem os dois filhos */
	      arvore* f = raiz->esquerda;
	      while (f->direita != NULL) {
		f = f->direita;
	      }
	      raiz->chave = f->chave; /* troca as informações */
	      f->chave = valor;
	      raiz->esquerda = arvore_remove(raiz->esquerda,valor);
	    }
	  }
	}
      }
    }
  }
  return raiz;
}

/*Função de busca*/
arvore* busca_arvore(arvore* raiz, int n) {

  if (raiz == NULL) {
    return NULL;
  } else {

    if (raiz->chave > n) {
      return busca_arvore (raiz->esquerda, n);
    } else {
      if (raiz->chave < n) {
	return busca_arvore (raiz->direita, n);
      } else {
	return raiz;
      }
    }
  }
}

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
