//
//  teste.c
//
//
//  Created by Janaína Rolan Loureiro on 04/06/14.
//
//

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct{
    char letra;
    bool cod[8];
    int dig;
    int freq;
} tabela;

struct no{
    struct no* esq;
    struct no* dir;
    char letra;
    int freq;
};
typedef struct no arvHuffman;

arvHuffman* criaArvore(){
    arvHuffman *raiz;
    raiz = (arvHuffman*)malloc(sizeof(arvHuffman));
    raiz->esq = raiz->dir = NULL;
    raiz->letra = 0;
    return raiz;
}

int procura(arvHuffman f[MAX], char c){
    int i = 0;

    while (f[i].letra != 0) {
        if (f[i].letra == c) {
            return i;
        }
        i++;
    }
    return i;
}

int calculaFrequencia(arvHuffman f[MAX], char frase[MAX]){

  int n=0,i=0,j;

  while(frase[i]!='\0'){

    for(j=0;j<n && frase[i]!=f[j].letra;j++);

    if(j==n) {
      f[j].letra=frase[i];
      f[j].freq=1;
      n++;
    } else {
      f[j].freq++;
    }
    i++;
  }

  return n;
}


arvHuffman *constroiHuffman(arvHuffman f[MAX], int n){

  arvHuffman *a,*b,*raiz;
  int j,aux,primeiro[2],segundo[2];

  aux=n;

  while(aux>1) {
    primeiro[0]=9999;
    segundo[0]=9999;
    primeiro[1]=0;
    segundo[1]=0;

    for(j=0;j<aux;j++){

      if(f[j].freq<primeiro[0]) {
	segundo[0]=primeiro[0];
	segundo[1]=primeiro[1];
	primeiro[0]=f[j].freq;
	primeiro[1]=j;
      } else {
	if(f[j].freq<segundo[0]){
	segundo[0]=f[j].freq;
	segundo[1]=j;
	}
      }

    }

    a = criaArvore();
    b = criaArvore();

    a->letra=f[primeiro[1]].letra;
    a->freq=f[primeiro[1]].freq;
    a->esq=f[primeiro[1]].esq;
    a->dir=f[primeiro[1]].dir;

    b->letra=f[segundo[1]].letra;
    b->freq=f[segundo[1]].freq;
    b->esq=f[segundo[1]].esq;
    b->dir=f[segundo[1]].dir;

    f[primeiro[1]].letra='*';
    f[primeiro[1]].freq=a->freq+b->freq;
    f[primeiro[1]].esq=a;
    f[primeiro[1]].dir=b;

    for(j=segundo[1];j<aux;j++){
      f[j].letra=f[j+1].letra;
      f[j].freq=f[j+1].freq;
      f[j].esq=f[j+1].esq;
      f[j].dir=f[j+1].dir;
    }

    aux--;
  }
    raiz = criaArvore();

    raiz->letra=f[0].letra;
    raiz->freq=f[0].freq;
    raiz->esq=f[0].esq;
    raiz->dir=f[0].dir;

    return raiz;

}



void anotaCodigo(arvHuffman* arv, tabela *t, int *i, bool codigo[8], int d)
{
  if(arv != NULL) {
    if(arv->letra=='*') {
      codigo[d]=0;
      anotaCodigo(arv->esq, t, i, codigo, d+1);
      codigo[d]=1;
      anotaCodigo(arv->dir, t, i, codigo, d+1);
    } else {
      t[*i].letra=arv->letra;
      t[*i].dig=d;
      t[*i].freq=arv->freq;
      for(int j=0;j<d;j++){
	t[*i].cod[j]=codigo[j];
      }
      (*i)++;
    }
  }
}


void compressao(char frase[MAX], tabela *t, int n){
  int i=0,j,k;
  while(frase[i]!='\0'){

    for(j=0;frase[i]!=t[j].letra;j++);

    for(k=0;k<t[j].dig;k++){
      printf("%d",t[j].cod[k]);
    }
    i++;
  }

  printf("\n");

}


void imprime(arvHuffman* raiz) {

  if (raiz != NULL) {

    printf("Letra:%c Freq:%d \n",raiz->letra,raiz->freq);
    imprime(raiz->esq);
    imprime(raiz->dir);
  }

}



int main()
{
  int n, i, j, indice = 0;
    arvHuffman *arv;
    char frase[MAX];
    bool codigo[8]={0};
    arvHuffman f[MAX] = {0};
    tabela *t;

    arv = NULL;
    arv = criaArvore();

    printf("Entre com a frase a ser compactada:\n");
    scanf("%[^\n]", frase);

    n = calculaFrequencia(f, frase);

    arv = constroiHuffman(f, n);

    printf("\nImprimindo a arvore:\n\n");
    imprime(arv);

    t = (tabela*)malloc(sizeof(tabela)*n);

    anotaCodigo(arv, t, &indice, codigo, 0);

    printf("\nImprimindo a tabela:\n\n");

    for(i=0;i<n;i++){
      printf("Letra: %c Freq: %d Cod: ",t[i].letra,t[i].freq);
      for(j=0;j<t[i].dig;j++){
	printf("%d",t[i].cod[j]);
      }
      printf("\n");
    }

    printf("\nCodigo:\n\n");
    compressao(frase, t, n);

    printf("\n");

    return 0;
}
