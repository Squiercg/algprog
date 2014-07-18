#include <stdio.h>
#include <string.h>


/*Estrutura para reads, contem a sequencia de dna do read, onde ele começa no codigo principal e onde termina*/
typedef struct {
  char sequencia[500];
  int inicio;
  int fim;
} dnaseq;


/*Compara duas sequencias, particular o fim da sequencia da esquerda com o inicio da direta, até encontrar ou maior
  match ou nenhum match, retornando 0*/
int comparaseq(char esquerda[],char direita[]){
  int ndir,nesq,i;

  ndir=strlen(direita);
  nesq=strlen(esquerda);

  while(ndir>0) {
    for(i=0;i<ndir && esquerda[(nesq-ndir)+i]==direita[i];i++);
    if(i==ndir) {
      return i;
    } else {
      ndir--;
    }
  }

  return 0;

}

/*Essa função recebe um vetor sequencias, a posição de duas sequencias (a,b), o tamanho do match entre esse a e b e o
numero total de sequencias em reads, ele vai fazer a união entre a e b, copiar essa união no menor indice, e deslocar
todo o vetor de reads para sobrepor o maior indice entre a e b, podendo assim descartar o ultimo read*/
void uniseq(dnaseq reads[],int a, int b, int n,int sequencias){

  char novo[500];
  int na,nb,i,j,primeiro,segundo;

  na=strlen(reads[a].sequencia);
  nb=strlen(reads[b].sequencia);

  for(i=0;i<(na-n);i++){
    novo[i]=reads[a].sequencia[i];
  }
  for(j=0;j<nb;j++){
    novo[i]=reads[b].sequencia[j];
    i++;
  }
  novo[i]='\0';

  if(a<b){
    primeiro=a;
    segundo=b;
  } else {
    primeiro=b;
    segundo=a;
  }

  i=0;
  while(novo[i]!='\0'){
    reads[primeiro].sequencia[i]=novo[i];
    i++;
  }
  reads[a].sequencia[i]='\0';

  for(i=segundo;i<(sequencias-1);i++) {
    j=0;
    while(reads[i+1].sequencia[j]!='\0'){
      reads[i].sequencia[j]=reads[i+1].sequencia[j];
      j++;
    }
    reads[i].sequencia[j]='\0';
  }
}

/*KMP*/
int KMP (char pad[], char txt[]){
    int i, j, k, d[500], m, n, teste;
    m = strlen(pad);
    n = strlen(txt);

    j = d[1] = 0;
    k = 1;
    while (k<m){
        if (pad[k]==pad[j]){
            k++;
            j++;
            d[k]=j;
        }
        else {
            if (j==0){
                k++;
                d[k]=0;
            }
            else
                j = d[j];
        }
    }

    i = j = 0;
    while ((i-j)<=(n-m)) {
        teste = 1;
        while (j<m && teste){
            if (txt[i]==pad[j]){
                i++;
                j++;
            }
            else
                teste = 0;
        }
        if (teste) {
            return i-m;
        }
        if (j==0)
            i++;
        else
            j = d[j];
    }
    return -1;
}

/*Um pequeno insertion sort para a estrutura usada, apenas para organizar os exón*/
void insertionsort(dnaseq reads[], int n) {
  int i,j;
  dnaseq aux;

  for(i=1;i<n;i++) {
    aux=reads[i];
    j=i-1;
    while(j>=0 && reads[j].inicio>aux.inicio) {
      reads[j+1]=reads[j];
      j=j-1;
    }
    reads[j+1]=aux;
  }
}


int main(void) {

  dnaseq reads[50],origem;
  int i,j,n,matriz[50][50],maior,k,l,temp1,temp2;

  /******************
   *Entrada de dados*
   ******************/
  scanf("\n%[^\n]",origem.sequencia);
  scanf("%d",&n);
  for(i=0;i<n;i++) {
    scanf("\n%[^\n]",reads[i].sequencia);
  }

  /*Verificação da entrada
  printf("Sequencia principal: %s\n",origem.sequencia);
  for(i=0;i<n;i++) {
    printf("Read %2.d: %s\n",i+1,reads[i].sequencia);
  }*/

  /*Fim da entrada de dados*/

  /****************
   *Processamento *
  *****************/
  /*Processando reads*/
  do{
  /*Comparando reads em todas as possibilidades*/
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
	if(i==j){
	  matriz[i][j]=0;
	} else {
	  matriz[i][j]=comparaseq(reads[i].sequencia,reads[j].sequencia);
	}
      }
    }
  /*Procurando o maior match, se existir*/
    maior=0;
    k=-1;
    l=-1;
    for(j=0;j<n;j++){
      for(i=0;i<n;i++){
	if(maior<=matriz[i][j]) {

	  if(maior==matriz[i][j]) {
	    temp1=strlen(reads[i].sequencia)+strlen(reads[j].sequencia)-matriz[i][j];
	    temp2=strlen(reads[k].sequencia)+strlen(reads[l].sequencia)-maior;

	    if(temp1<temp2){
	      k=i;
	      l=j;
	      maior=matriz[i][j];
	    }

	  } else {
	    k=i;
	    l=j;
	    maior=matriz[i][j];
	  }
	}
      }
    }
  /*Se encontrado, fazer uma união*/
    if(maior>0) {
      uniseq(reads,k,l,maior,n);
      /*Diminuimos o n em 1*/
      n--;
    }
    /*continuaremos esse procedimento até que não haja reads com possiblidade de união ou tenhamos apenas um read*/
  }while(maior!=0 && n>1);

  /*Encontrar reads n a origem*/

  /*Saida de dados*/

  for(i=0;i<n;i++) {
    reads[i].inicio=KMP(reads[i].sequencia,origem.sequencia);
    reads[i].fim=reads[i].inicio+strlen(reads[i].sequencia)-1;
  }

  insertionsort(reads,n);

  /*Impressão Intron*/
  i=0;
  if(reads[0].inicio>0){
    for(j=0;j<reads[i].inicio;j++){
      printf("%c",origem.sequencia[j]);
    }
    printf(" ->Intron: [%d , %d]\n",0,reads[i].inicio-1);
  }

  for(i=0;i<(n-1);i++) {
    for(j=reads[i].fim+1;j<reads[i+1].inicio;j++){
      printf("%c",origem.sequencia[j]);
    }
    printf("->Intron: [%d , %d]\n",reads[i].fim+1,reads[i+1].inicio-1);
  }

  k=strlen(origem.sequencia);
  if(reads[i].fim<(k-1)){
    for(j=reads[i].fim+1;j<k;j++){
      printf("%c",origem.sequencia[j]);
    }
    printf(" ->Intron: [%d , %d]\n",reads[i].fim,k-1);

  }

  /*Impressão Exon*/
  for(i=0;i<n;i++) {
    printf("%s ->Éxon: [%d , %d]\n",reads[i].sequencia,reads[i].inicio,reads[i].fim);
  }

  return 0;
}

