/*Augusto Cesar de Aquino Ribas
Thiago M.*/

#include <stdio.h>
#include <string.h>

#define ALF 27
#define MAXP 100
#define MTEX 1000

int n;

int preBM(char padrao[MAXP],char v1[] , int v2[]){
  int n=0,l=0,i,j,busca;

  while (padrao[n] != '\0') {

/*Primeiro eu busco a letra na minha matriz de pre-processo*/
    busca=0;
    for(i=0;i<l;i++) {
      if(padrao[n]==v1[i]) {
	busca=1;
      }
    }

/*Se não encontrar eu insiro*/
    if(busca==0) {
      v1[l]=padrao[n];
      l++;
    }
    n++;
  }

  for(i=0;i<l;i++) {
    for(j=(n-1);j<n && padrao[j]!=v1[i];j--);
    v2[i]=(n-1)-j;
  }

  v1[l]='*';
  v2[l]=n;

  /* Aqui imprime o pre-processamento, para testar
  for(i=0;i<=l;i++) {
    printf("Letra: %c Posicao:%d\n",v1[i],v2[i]);
  }
  */

  return n;
}

/*
Boa tarde Augusto,

Vamos lá: para o algoritmo, você vai basicamente precisar de um i para cuidar do texto e um j do padrão, como você fez,
 então ok. Na hora de andar, inicialmente você tem que ir comparando texto[i+j] com padrao[j], sendo j iniciado com 0,
 assim como é feito no algoritmo do kmp. Quando o seu padrão acabar (deu casamento) ou quando houver uma comparação que
 resulte em falso, esse procedimento encerra-se. Em caso de casamento, retorne i. Caso contrário, percorra seu vetor do
 pré-processamento buscando o caractere de texto[i+m], sendo m o tamanho do padrão. Adiante i o número relacionado com
 o caractere em questão no pré processamento, ou seja, se  texto[i+m] está associado a 3, você deve fazer i+3, e então
 reiniciar o processo. Espero ter ajudado :)

Atenciosamente,
*/

int BM(char padrao[MAXP], char v1[],int v2[], char texto[MTEX], int k){

  int i,j,a,b,aux,busca=-1,fim=0;

  i=0;
  j=0;

  /*Verificando o texto*/
  while(texto[i]!='\0' && fim==0) {
    i++;

  /*Primeiro a gente olha aonde bate, sendo que o j vai parar de aumentar na primeira vez que não vater o padraovs texto*/
    for(j=0;j<k && texto[i+j]==padrao[j];j++);


    if(j==k){
      /*Dai se j==k, que é o tamanho do padrão, bateu, e retornamos o i*/
      return i+1;
    } else {
      /*Senão vamos procurar no nosso pre-processamento quanto aumentar o i, se tiver no pre-processamento a letra
aumentamos a quantidade dela, que está no v2, senão aumentamos o *, que é o tamanho do padrao, o resto*/
      for(a=0;texto[i+k]!=v1[a] && v1[a]!='*';a++);
      i=i+v2[a];
    }
  }

  return -1;
}




int main(void){

    int k, v2[ALF], bm;
    char padrao[MAXP], texto[MTEX],v1[ALF];

    scanf("%s %s", texto, padrao);
    printf("Padrao: %s\n",padrao);

    k = preBM(padrao,  v1, v2);

    printf("Texto: %s\n",texto);

    bm = BM(padrao, v1, v2, texto, k);

    printf("Ocorrencia inicia na posição %d\n", bm);

    return 0;
}
