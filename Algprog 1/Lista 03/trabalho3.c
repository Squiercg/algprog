/*********************************************************
 * Nome: Augusto Cesar de Aquino Ribas                   *
 * Atividade de Algoritimos de Programação I, turma 3    *
 *Professor: Marco Aurélio Stefanes                      *
 *********************************************************
 */
#include <stdio.h>


/*Esse programa primeiro recebe um inteiro que é o número de jogos que serão avaliados,
depois ele recebe uma matriz de letras e palavras para procurar, apontando então a localização
da primeira letra quando a palavra for encontrada */


typedef struct{
  char palavra[51];
} registro;

/* Essa função procura por uma letra, percorrendo todas as colunas de uma linha então pulando
para a proxima linha, ela recebe a letra a ser procurada, uma matriz de letras, as dimensões m
e n da matriz e o local aonde começar a procurar, então então vai procurar a partir da proxima letra
e fazer um update do vetor local recebido que contem a linha e coluna da letra, ao fim da matriz, se a letra
não puder ser encontrada, será retornado -1 para o valor de linha e coluna, representando que a matriz não
contem mais ocorrencias apos a ultima posição fornecida*/
void achaletra(char x,char matriz[50][50], int m , int n, int local[2] ) {
  int i,j;

/*Se a entrada de local for -1 -1, significa que temos que começar a procurar
da primeira posição da matriz, linha 0 e coluna 0, caso contrarior começamos
na proxima letra*/

  if(local[0]==-1) {
    i=0;
    j=0;
  } else {
    i=local[0];
    j=local[1]+1;
  }

  do{

    if(x==matriz[i][j]) {
      local[0]=i;
      local[1]=j;
      i=m+1;
    }

    if(j<n) {
      j++;
    } else {
      i++;
      j=0;
    }

  } while(i<m);

  if(i==m) {
  local[0]=-1;
  local[1]=-1;
  }

}

/*A partir daqui, até o inicio da main existem oito funções semelhantes.
Basicamente elas recebem uma palavra, uma matriz de letras e suas dimensões
e uma posição (linha e coluna) nessa matriz e retorna 1 se essa palavra esta
completa na matriz de letras e zero se esta palavra esta incompleta. Cada função
faz a busca em um sentido da matriz, usando os nomes dos pontos cardeais para
sugerir o sentido que será procurado*/

/*Testando para o Norte*/
int cnorte(char palavra[],char matriz[50][50],int m,int n, int local[2] ) {
  int x , i , j;
  char letra;
  /*Pegando a segunda letra da palavra, a primeira ja foi encontrada com a
 função acha letra*/
  x=1;
  letra=palavra[x];

  /*Escolhendo a proxima posição para este sentido, dado a posição de entrada, note que
  aqui é diferente para cada função*/
  i=local[0]-1;
  j=local[1];

  /*Agora enquanto não chegarmos ao fim da palavra ('\0') ou os estremos da matriz
  continuamos verificando letra a letra, se a palavra esta presente*/
  while( (letra!='\0') && (i>=0 && i<m) && (j>=0 && j<n) ) {

    /*Enquanto encontrarmos uma correspondencia das letras, alteramos os indices
   correspondentes a direção que estamos indo na matriz e pegamos a proxima letra*/
    if(letra==matriz[i][j]) {
      i--;
      x++;
      letra=palavra[x];
    } else {
      /*Caso contrario modificamos um indice para encerrar o laço*/
      i=m;
    }

  }

  /*Caso chegamos ao fim da palavra, retornamos 1, caso contrario zero*/
  if(letra=='\0') {
    return 1;
  } else {
    return 0;
  }
}

/*A partir daqui até o inicio da função main é mais do mesmo, apenas o indice é mudado,
tanto da primeira letra testada como a modificação do i e j dentro do laco de while*/
/*Testando para o Sul*/
int csul(char palavra[],char matriz[50][50],int m,int n, int local[2] ) {
  int x , i , j;
  char letra;

  x=1;
  letra=palavra[x];
  i=local[0]+1;
  j=local[1];

  while( (letra!='\0') && (i>=0 && i<m) && (j>=0 && j<n) ) {

    if(letra==matriz[i][j]) {
      i++;
      x++;
      letra=palavra[x];
    } else {
      i=m;
    }

  }

  if(letra=='\0') {
    return 1;
  } else {
    return 0;
  }
}

/*Testando para o leste*/
int cleste(char palavra[],char matriz[50][50],int m,int n, int local[2] ) {
  int x , i , j;
  char letra;

  x=1;
  letra=palavra[x];
  i=local[0];
  j=local[1]+1;

  while( (letra!='\0') && (i>=0 && i<m) && (j>=0 && j<n) ) {

    if(letra==matriz[i][j]) {
      j++;
      x++;
      letra=palavra[x];
    } else {
      i=m;
    }

  }

  if(letra=='\0') {
    return 1;
  } else {
    return 0;
  }
}

/*Testando para o oeste*/
int coeste(char palavra[],char matriz[50][50],int m,int n, int local[2] ) {
  int x , i , j;
  char letra;

  x=1;
  letra=palavra[x];
  i=local[0];
  j=local[1]-1;

  while( (letra!='\0') && (i>=0 && i<m) && (j>=0 && j<n) ) {

    if(letra==matriz[i][j]) {
      j--;
      x++;
      letra=palavra[x];
    } else {
      i=m;
    }

  }

  if(letra=='\0') {
    return 1;
  } else {
    return 0;
  }
}

/*Testando para o nordeste*/
int cnordeste(char palavra[],char matriz[50][50],int m,int n, int local[2] ) {
  int x , i , j;
  char letra;

  x=1;
  letra=palavra[x];
  i=local[0]-1;
  j=local[1]+1;

  while( (letra!='\0') && (i>=0 && i<m) && (j>=0 && j<n) ) {

    if(letra==matriz[i][j]) {
      i--;
      j++;
      x++;
      letra=palavra[x];
    } else {
      i=m;
    }

  }

  if(letra=='\0') {
    return 1;
  } else {
    return 0;
  }
}


/*Testando para o sudeste*/
int csudeste(char palavra[],char matriz[50][50],int m,int n, int local[2] ) {
  int x , i , j;
  char letra;

  x=1;
  letra=palavra[x];
  i=local[0]+1;
  j=local[1]+1;

  while( (letra!='\0') && (i>=0 && i<m) && (j>=0 && j<n) ) {

    if(letra==matriz[i][j]) {
      i++;
      j++;
      x++;
      letra=palavra[x];
    } else {
      i=m;
    }

  }

  if(letra=='\0') {
    return 1;
  } else {
    return 0;
  }
}


/*Testando para o noroeste*/
int cnoroeste(char palavra[],char matriz[50][50],int m,int n, int local[2] ) {
  int x , i , j;
  char letra;

  x=1;
  letra=palavra[x];
  i=local[0]-1;
  j=local[1]-1;

  while( (letra!='\0') && (i>=0 && i<m) && (j>=0 && j<n) ) {

    if(letra==matriz[i][j]) {
      i--;
      j--;
      x++;
      letra=palavra[x];
    } else {
      i=m;
    }

  }

  if(letra=='\0') {
    return 1;
  } else {
    return 0;
  }
}

/*Testando para o sudoeste*/
int csudoeste(char palavra[],char matriz[50][50],int m,int n, int local[2] ) {
  int x , i , j;
  char letra;

  x=1;
  letra=palavra[x];
  i=local[0]+1;
  j=local[1]-1;

  while( (letra!='\0') && (i>=0 && i<m) && (j>=0 && j<n) ) {

    if(letra==matriz[i][j]) {
      i++;
      j--;
      x++;
      letra=palavra[x];
    } else {
      i=m;
    }

  }

  if(letra=='\0') {
    return 1;
  } else {
    return 0;
  }
}

/*Inicio da função main*/

int main(void)
{
  int m , n , i , j , k , local[2],vezes,cont;
  char matriz[50][50];
  registro procura[20];

  /*Primeiro vemos quantas vezes o jogo será avaliado*/
  scanf("%d",&vezes);

  for(cont=1;cont<=vezes;cont++) {

    /*Dimensões da matriz*/
    scanf("%d %d",&m , &n);

    /*Entrada da matriz, o \n no inicio previne que a matriz também
seja preenchida com \n*/

    for(i=0;i<m;i++) {
      for(j=0;j<n;j++) {
	scanf("\n%c",&matriz[i][j]);
      }
    }

    /*Palavras a serem avaliadas*/
    scanf("%d",&k);

    for(i=0;i<k;i++) {
      scanf(" %[^\n]",procura[i].palavra);
    }
    /*Fim da entrada de dados*/

    /*Iniciando a variavel local fora da area da matriz*/
    local[0]=-1;
    local[1]=-1;

    /*Avaliações por palavras*/
    for(i=0;i<k;i++) {

      do {

      /*Primeiro procuramos a primeira letra da palavra*/
	achaletra(procura[i].palavra[0],matriz,m,n,local);

	/*Depois verificamos se ela ocorre em algum sentido na matriz, se sim
a gente imprime a localização e encerra as buscas, ja que devemos retornar somente
a primeira ocorrencia da palavra*/
	if( cnorte(procura[i].palavra,matriz,m,n,local)     ||
	    csul(procura[i].palavra,matriz,m,n,local)       ||
	    cleste(procura[i].palavra,matriz,m,n,local)     ||
	    coeste(procura[i].palavra,matriz,m,n,local)     ||
	    cnordeste(procura[i].palavra,matriz,m,n,local)  ||
	    csudeste(procura[i].palavra,matriz,m,n,local)   ||
	    csudoeste(procura[i].palavra,matriz,m,n,local)  ||
	    cnoroeste(procura[i].palavra,matriz,m,n,local)  ){
	  /*imprimimos o local e reiniciamos a variavel local para aproxima palavra*/
	  printf("%d %d\n",local[0]+1,local[1]+1);
	  local[0]=-1;
	  local[1]=-1;

	}

	/*Aqui encontraremos essa condição em dois casos, se chegarmos ao fim da matriz de letras,
esse local é retornado e se encontramos a posição da palavra, modificamos a variavel local para
finalizar esse laço*/
      } while(  (local[0]!=-1) && (local[1]!=-1) );

    }
    printf("\n");
  }

  return 0;
}
