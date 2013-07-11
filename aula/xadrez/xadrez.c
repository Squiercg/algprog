#include <stdio.h>

typedef struct{
  char peca;
  int linha , coluna;
} peca;


/*Testa se é check, por enquanto so funciona com o peão, ai a ideia é ir adicionando peças*/
int xeque(peca rei , peca adversario , char cor) {


  /*testando o peão*/
  if(cor=='b' && adversario.peca=='P') {
    if(  ((rei.linha-1==adversario.linha-1) && (rei.coluna-1==adversario.coluna-1 ))  ||
	  ((rei.linha+1==adversario.linha+1) && (rei.coluna-1==adversario.coluna-1))  )
      return 1;
    exlse
      return 0;
  } else {
    if( ((rei.linha-1==adversario.linha-1) && (rei.coluna+1==adversario.coluna+1))  ||
        ((rei.linha+1==adversario.linha+1) && (rei.coluna+1==adversario.coluna+1)) )
      return 1;
    else
      return 0;
  }
  /*fim do teste do peão*/

  return 666;
}

/*aqui eu so estou fazendo uma função pra fazer uma matriz, porque pra torre eu tenho que testar se nao tem nada
  no caminho correto? Futuramente o tabuleiro vai em junto pro teste xeque*/
void tabu(peca ataca[], int a, peca defende[] , int d ,peca remove, int tabuleiro[8][8]) {
  int i;
  for(i=0;i<a;i++) {
    tabuleiro[ataca[i].linha][ataca[i].coluna]=1;
  }
  for(i=0;i<d;i++) {
    tabuleiro[defende[i].linha][defende[i].coluna]=1;
  }

  tabuleiro[remove.linha][remove.coluna]=0;
}



int main(void)
{
  peca branca[16], preta[16],  movimento[2];
  char coluna[2];
  int b,p,i,j,linha[2], tabuleiro[8][8]={{0}};


  scanf("%d",&b);

  for(i=0;i<b;i++) {
    scanf("\n %c %d%c",&branca[i].peca,&linha[0],&coluna[0]);
    branca[i].linha=linha[0]-1;
   branca[i].coluna=coluna[0]-97;
  }

  scanf("%d",&p);

  for(i=0;i<p;i++) {
    scanf("\n %c %d%c",&preta[i].peca,&linha[0],&coluna[0]);
    preta[i].linha=linha[0]-1;
    preta[i].coluna=coluna[0]-97;
  }

  scanf("\n %c %d%c %d%c",&movimento[0].peca,&linha[0],&coluna[0],&linha[1],&coluna[1]);
  movimento[0].linha=linha[0]-1;
  movimento[0].coluna=coluna[0]-97;
  movimento[1].peca=movimento[0].peca;
  movimento[1].linha=linha[1]-1;
  movimento[1].coluna=coluna[1]-97;


  tabu(branca,b, preta , p ,preta[0], tabuleiro);

  /*Aqui é so um teste pra ver se ta preenchendo certo a matriz*/
  for(i=0;i<8;i++) {
    for(j=0;j<8;j++) {
      printf("%3d ",tabuleiro[i][j]);
    }
    printf("\n");
  }

  /*Aqui é o uso do teste em si, 0 para não esta em xeque e 1 para esta em xeque*/
  printf("%d\n",xeque(branca[1],preta[0],'b'));



  return 0;
}



