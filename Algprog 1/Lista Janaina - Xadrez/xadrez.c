/*****************************************
 *Aluno: Augusto Cesar de Aquino Ribas   *
 *Trabalho: Xadrez                       *
 *Algoritimos de programação I turma 03  *
 *Professora: Janaína Rolan Loureiro     *
 *****************************************
 */
#include <stdio.h>

/*Esse programa recebe a posição de todas as peças de um tabuleiro e a ultima movimentação de um jogador e retorna se
essa ultima movimentação é valida e se coloca em check o rei adversario*/


/*Definindo uma estrutura de dados para receber as peças*/
typedef struct{
  char peca;
  int linha , coluna;
} peca;

/*Função para encontrar o Rei, ela recebe um tabuleiro e retorna a posição do rei
onde a dezena é a linha e a unidade é a coluna */
int reipos(int tabuleiro[8][8]) {
  int i , j , saida;

  for(i=0;i<8;i++) {
    for(j=0;j<8;j++) {
      if(tabuleiro[i][j]==6) {
	saida=(i*10)+j;
      }
    }
  }

  return saida;

}

/*Abaixo estão quatro funções que testam se o rei está em cheque, o oponente tem suas peça com valores negativos
no tabuleiro. Em caso do rei ser ameaçado por alguma peça, as funções retornaram 1, caso contrario é retornado 0*/

/* Peão */
int peao(int tabuleiro[8][8]) {
  int i,j,n;

  n=reipos(tabuleiro);
  i=n/10;
  j=n%10;

  if(tabuleiro[i+1][j+1]==-1)
    return 1;
  if(tabuleiro[i+1][j-1]==-1)
    return 1;
  if(tabuleiro[i-1][j+1]==-1)
    return 1;
  if(tabuleiro[i-1][j-1]==-1)
    return 1;

  return 0;

}

/* Cavalo */
int cavalo(int tabuleiro[8][8]) {
  int i,j,n;

  n=reipos(tabuleiro);
  i=n/10;
  j=n%10;

  if(tabuleiro[i+1][j+2]==-3)
    return 1;
  if(tabuleiro[i+1][j-2]==-3)
    return 1;
  if(tabuleiro[i-1][j+2]==-3)
    return 1;
  if(tabuleiro[i-1][j-2]==-3)
    return 1;
  if(tabuleiro[i+2][j+1]==-3)
    return 1;
  if(tabuleiro[i+2][j-1]==-3)
    return 1;
  if(tabuleiro[i-2][j+1]==-3)
    return 1;
  if(tabuleiro[i-2][j-1]==-3)
    return 1;

  return 0;

}

/* Torre e Rainha */
/*Testamos a rainha também aqui, ja que os movimentos desta é uma combinação do bispo e da torre*/
int torre(int tabuleiro[8][8]) {
  int i,j,n;

  n=reipos(tabuleiro);
  i=n/10;
  j=n%10;

  for(n=i;n<8;n++)
    if( tabuleiro[n][j]!=0 && (tabuleiro[n][j]==-2 || tabuleiro[n][j]==-5) )
      return 1;

  for(n=i;n>=0;n--)
    if( tabuleiro[n][j]!=0 && (tabuleiro[n][j]==-2 || tabuleiro[n][j]==-5) )
      return 1;

  for(n=j;n<8;n++)
    if( tabuleiro[i][n]!=0 && (tabuleiro[i][n]==-2 || tabuleiro[i][n]==-5) )
      return 1;

  for(n=j;n>=0;n--)
    if( tabuleiro[i][n]!=0 && (tabuleiro[i][n]==-2 || tabuleiro[i][n]==-5) )
      return 1;

  return 0;

}


/* Bispo */
int bispo(int tabuleiro[8][8]) {
  int i,j,n,l,c;

  n=reipos(tabuleiro);
  i=n/10;
  j=n%10;

  for(l=i,c=j;l<8 && c<8;l++,c++)
    if( tabuleiro[l][c]!=0 && (tabuleiro[l][c]==-4 || tabuleiro[l][c]==-5) )
      return 1;

  for(l=i,c=j;l<8 && c>=0;l++,c--)
    if( tabuleiro[l][c]!=0 && (tabuleiro[l][c]==-4 || tabuleiro[l][c]==-5) )
      return 1;

  for(l=i,c=j;l>=0 && c<8;l--,c++)
    if( tabuleiro[l][c]!=0 && (tabuleiro[l][c]==-4 || tabuleiro[l][c]==-5) )
      return 1;

  for(l=i,c=j;l>=0 && c>=0;l--,c--)
    if( tabuleiro[l][c]!=0 && (tabuleiro[l][c]==-4 || tabuleiro[l][c]==-5) )
      return 1;

  return 0;

}

/*Iniciando a função main*/
int main(void)
{
  peca branca[16], preta[16],  movimento[2];
  char coluna[2];
  int b,p,i,j,linha[2], tabuleiro[8][8]={{0}};

  /*Entrada de dados */

  /*Recebendo peças brancas e pretas */
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

  /*Recebendo o ultimo movimento */
  scanf("\n %c %d%c %d%c",&movimento[0].peca,&linha[0],&coluna[0],&linha[1],&coluna[1]);
  movimento[0].linha=linha[0]-1;
  movimento[0].coluna=coluna[0]-97;
  movimento[1].peca=movimento[0].peca;
  movimento[1].linha=linha[1]-1;
  movimento[1].coluna=coluna[1]-97;

 /* Codificando as peças num tabuleiro como uma matriz de inteiros
1 - peao (P)
2 - torre (T)
3 - cavalo (C)
4 - bispo (B)
5 - dama (D)
6 - rei (R)
*/

  /*Peças brancas*/
  for(i=0;i<b;i++) {

    if(branca[i].peca=='P')
      tabuleiro[branca[i].linha][branca[i].coluna]=1;
    else
      if(branca[i].peca=='T')
	tabuleiro[branca[i].linha][branca[i].coluna]=2;
      else
	if(branca[i].peca=='C')
	  tabuleiro[branca[i].linha][branca[i].coluna]=3;
	else
	  if(branca[i].peca=='B')
	    tabuleiro[branca[i].linha][branca[i].coluna]=4;
	  else
	    if(branca[i].peca=='D')
	      tabuleiro[branca[i].linha][branca[i].coluna]=5;
	    else
	      tabuleiro[branca[i].linha][branca[i].coluna]=6;
  }

  /*Peças pretas*/
  for(i=0;i<p;i++) {

    if(preta[i].peca=='P')
      tabuleiro[preta[i].linha][preta[i].coluna]=-1;
    else
      if(preta[i].peca=='T')
	tabuleiro[preta[i].linha][preta[i].coluna]=-2;
      else
	if(preta[i].peca=='C')
	  tabuleiro[preta[i].linha][preta[i].coluna]=-3;
	else
	  if(preta[i].peca=='B')
	    tabuleiro[preta[i].linha][preta[i].coluna]=-4;
	  else
	    if(preta[i].peca=='D')
	      tabuleiro[preta[i].linha][preta[i].coluna]=-5;
	    else
	      tabuleiro[preta[i].linha][preta[i].coluna]=-6;
  }

/*Ultimo movimento */
  tabuleiro[movimento[0].linha][movimento[0].coluna]=0;

  if(movimento[1].peca=='P')
    tabuleiro[movimento[1].linha][movimento[1].coluna]=1;
    else
      if(movimento[i].peca=='T')
	tabuleiro[movimento[1].linha][movimento[1].coluna]=2;
      else
	if(movimento[1].peca=='C')
	  tabuleiro[movimento[1].linha][movimento[1].coluna]=3;
	else
	  if(movimento[1].peca=='B')
	    tabuleiro[movimento[1].linha][movimento[1].coluna]=4;
	  else
	    if(movimento[1].peca=='D')
	      tabuleiro[movimento[1].linha][movimento[1].coluna]=5;
	    else
	      tabuleiro[movimento[1].linha][movimento[1].coluna]=6;

/*Fim da entrada de dados */

/*testando se o rei branco está em cheque*/
  if(peao(tabuleiro) || cavalo(tabuleiro) || torre(tabuleiro) || bispo(tabuleiro))
    b=1;
  else
    b=0;

  /*invertendo a matriz para usar as mesmas funções*/
  for(i=0;i<8;i++) {
    for(j=0;j<8;j++) {
      tabuleiro[i][j]=-1*tabuleiro[i][j];
    }
  }


/*testando se o rei preto está em cheque*/
  if(peao(tabuleiro) || cavalo(tabuleiro) || torre(tabuleiro) || bispo(tabuleiro))
    p=1;
  else
    p=0;

  /*Em caso do rei branco não estar em cheque porem o rei preto estar temos:*/
  if(b==0 && p==1) {
    printf("Jogada válida e dando xeque no oponente.\n");
  } else {
  /*Em caso do rei branco não estar em cheque porem não colocar o rei preto em cheque:*/
    if(b==0) {
      printf("Jogada válida, porém sem xeque no oponente.\n");
    } else {
  /*Se nenhum dos casos acima é verdadeiro, então:*/
      printf("Jogada invalida, jogador ficará em xeque se mover esta peça.\n");
    }
  }

  return 0;
}
