#include <stdio.h>

typedef struct{
  char peca;
  int linha , coluna;
} registro;


int main(void)
{
  registro peca[2][16],  movimento[2];
  char coluna[2];
  int b,p,i,linha[2], tabuleiro[8][8]={{0}};

  scanf("%d",&b);

  for(i=0;i<b;i++) {
    scanf("\n %c %d%c",&peca[0][i].peca,&linha[0],&coluna[0]);
    peca[0][i].linha=linha[0]-1;
    peca[0][i].coluna=coluna[0]-97;
  }

  scanf("%d",&p);

  for(i=0;i<p;i++) {
    scanf("\n %c %d%c",&peca[1][i].peca,&linha[0],&coluna[0]);
    peca[1][i].linha=linha[0]-1;
    peca[1][i].coluna=coluna[0]-97;
  }

  scanf("\n %c %d%c %d%c",&movimento[0].peca,&linha[0],&coluna[0],&linha[1],&coluna[1]);
  movimento[0].linha=linha[0]-1;
  movimento[0].coluna=coluna[0]-97;
  movimento[1].peca=movimento[0].peca;
  movimento[1].linha=linha[1]-1;
  movimento[1].coluna=coluna[1]-97;

  for(i=0;i<b;i++) {
    tabuleiro[peca[0][i].linha][peca[0][i].coluna]=peca[0][i].peca;
  }

  for(i=0;i<p;i++) {
    tabuleiro[peca[1][i].linha][peca[1][i].coluna]=peca[1][i].peca;
  }

  for(i=0;i<8;i++)
    for(j=0

  printf("fim\n");

  for(i=0;i<b;i++)
  printf("Peça: %c linha: %d coluna: %d\n",peca[0][i].peca,peca[0][i].linha,peca[0][i].coluna);

  return 0;
}
