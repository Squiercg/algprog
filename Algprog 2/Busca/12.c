#include <stdio.h>
#define MAX 100


int busca_binaria_char(int n, char matriz[MAX][MAX], char palavra[MAX]) {
  int esq, dir, meio , i;
  esq = -1;
  dir = n;

  i=0;
  while (esq < dir - 1) {

    meio = (esq + dir) / 2;

    if (matriz[meio][i] < palavra[i]) {
      esq = meio;
    } else {
      if( (matriz[meio][i] == palavra[i]) && (palavra[i]!='\0') ) {
	i++;
      } else {
      dir = meio;
      }
    }

  }

  i=0;
  while(palavra[i]!='\0' && matriz[dir][i]!='\0') {
    i++;
  }

  if(!(palavra[i]=='\0' && matriz[dir][i]=='\0')) {
    dir=-1;
  }

  return dir;
}



int main(void)
{
  int n, i , saida ;
  char matriz[MAX][MAX],palavra[MAX];

  printf("Número de palavras: ");
  scanf("%d",&n);

  printf("Entre as %d palavras: ",n);
  for(i=0;i<n;i++) {
    scanf(" %[^\n]",matriz[i]);

  }

  printf("Entre com a palavra buscada: ");
  scanf(" %[^\n]",palavra);

  printf("\nMatriz\n");
  for(i=0;i<n;i++) {
    printf("%s\n",matriz[i]);

  }

  saida=busca_binaria_char(n,matriz,palavra);


  if(saida==-1) {
    printf("Palavra ausente.\n");
  } else {
    printf("Palavra presente.\n");
  }

  return 0;

}
