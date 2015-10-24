/**************************************************
*
* Augusto Cesar de Aquino Ribas
* Trabalho 1
* Professor(a): Marco Aurelio Stefanis
*
*/
#include <stdio.h>
#define MAX_PILOTOS 50
#define MAX_EQUIPES 50
#define MAX_NOME 100
#define MAX 100

void troca(int *x , int *y){
  int aux;
  aux=*x;
  *x=*y;
  *y=aux;
}

int separa(int p, int r, int vetor[2][MAX]) {
  int x, i, j;
  x = vetor[1][p];
  i = p - 1;
  j = r + 1;
  while (1) {
    do {
      j--;
    } while (vetor[1][j] > x);
    do {
      i++;
    } while (vetor[1][i] < x);
    if (i < j) {
      troca(&vetor[0][i], &vetor[0][j]);
      troca(&vetor[1][i], &vetor[1][j]);
    } else {
      return j;
    }
  }
}

void quicksort(int p, int r, int vetor[2][MAX]) {
  int q;

  if (p < r) {
    q = separa(p, r, vetor );
    quicksort(p, q, vetor );
    quicksort(q+1, r, vetor );
  }

}

/* Armazena informações de um piloto */
typedef struct {
  char nome[MAX_NOME+1];
  int equipe;
  int pontos;
  int chegadas[3];
  int classif[MAX_PILOTOS];
} plt;
/* Armazena informações de uma equipe */
typedef struct {
  char nome[MAX_NOME+1];
  int chegadas[3];
  int pontos;
} equ;
/* Armazena informações de um campeonato */
typedef struct {
  char nome[MAX_NOME+1];
  int num_plts;
  plt piloto[MAX_PILOTOS];
  int num_equs;
  equ equipe[MAX_EQUIPES];
  int qtd_pontos;
  int sistema_pt[MAX_PILOTOS];
} cmp;

typedef struct {
  int indice;
  int pontos;
  int primeiro;
  int segundo;
  int terceiro;
  char *nome;
} qult;

int compara_cadeia(char cadeia1[], char cadeia2[]) {
  int i=0;

  while(cadeia2[i]!='\0') {
    if(cadeia2[i]==cadeia1[i]) {
      i++;
    } else {
      return -1;
    }
  }
  return 1;
}


int main(void)
{
  /*Indices*/
  int i, j , k, l;
  /*Variaveis referentes ao campeonato*/
  int p, aux, q, ncamps;
  int quali_plt[2][100], quali_equs[2][100];
  qult q_pilotos[100], q_equipe[100];
  /*Outras variaveis de interesse*/
  cmp campeonato[50];
  char cadeia[100], cadeiaaux[100], pilotoaux[100], equipeaux[100];

  scanf("%d",&ncamps);

  for(l=0;l<ncamps;l++) {


  /*Entrada de dados*/

  /*Nome do Campeonato*/
  scanf("\n%[^\n]",campeonato[l].nome);

  /*Número de pilotos*/
  scanf("%d",&p);
  campeonato[l].num_equs=0;

  /*Cadastro de pilotos e equipes*/
  for(i=0;i<p;i++) {
    /*Cadastro Do piloto, todos são cadastrados*/
    scanf("\n%[^,]",campeonato[l].piloto[i].nome);
    campeonato[l].num_plts++;

  /*Cadastro da equipe, cada equipe pode ter mais de um piloto, logo temos que verificar se ela ja existe*/
    scanf(", %[^\n]",cadeia);

    j=0;
    aux=-1;
    while(j<campeonato[l].num_equs) {
      aux=compara_cadeia(cadeia,campeonato[l].equipe[j].nome);
      j++;
    }

  /*Aqui a variaveis aux sera -1 se a equipe nao exister, se existir, j sera o seu indice*/
    if(aux==-1) {
      k=0;
      while(cadeia[k]!='\0'){
	campeonato[l].equipe[campeonato[l].num_equs].nome[k]=cadeia[k];
	k++;
      }
      campeonato[l].equipe[campeonato[l].num_equs].nome[k]=cadeia[k];
      campeonato[l].piloto[i].equipe=campeonato[l].num_equs;
      campeonato[l].num_equs++;
    } else {
      campeonato[l].piloto[i].equipe=j-1;
    }

  }

  /*Cadastro do sistema de pontuação*/
  scanf("%d",&campeonato[l].qtd_pontos);

  /*Pontos ganhos por colocação*/
  for(i=0;i<campeonato[l].qtd_pontos;i++){
    scanf("%d",&campeonato[l].sistema_pt[i]);
  }

  /*Número de corridas*/

  scanf("%d",&q);

  /*Zerando as pontuações*/
  for(i=0;i<campeonato[l].num_plts;i++){
   campeonato[l].piloto[i].pontos=0;
   campeonato[l].piloto[i].chegadas[0]=0;
   campeonato[l].piloto[i].chegadas[1]=0;
   campeonato[l].piloto[i].chegadas[2]=0;
  }
  for(i=0;i<campeonato[l].num_equs;i++){
    campeonato[l].equipe[i].pontos=0;
    campeonato[l].equipe[i].chegadas[0]=0;
    campeonato[l].equipe[i].chegadas[1]=0;
    campeonato[l].equipe[i].chegadas[2]=0;
  }
  for(i=campeonato[l].qtd_pontos;i<campeonato[l].num_plts;i++)
    campeonato[l].sistema_pt[i]=0;

  for(i=0;i<q;i++) {
  /*Nome da corrida*/
    scanf("\n%[^\n]",cadeiaaux);

    /*Pilotos que pontuaram*/
    for(j=0;j<campeonato[l].num_plts;j++) {
      scanf("\n %[^,]",pilotoaux);

      k=0;
      while(k<campeonato[l].num_plts) {
	if(compara_cadeia(pilotoaux,campeonato[l].piloto[k].nome)==1) {
	  campeonato[l].piloto[k].pontos+=campeonato[l].sistema_pt[j];
	  if(j==0){
	    campeonato[l].piloto[k].chegadas[0]++;
	  }
	  if(j==1){
	    campeonato[l].piloto[k].chegadas[1]++;
	  }
	  if(j==2){
	    campeonato[l].piloto[k].chegadas[2]++;
	  }
	  k=campeonato[l].num_plts;
	} else {
	  k++;
	}
      }


      scanf(", %[^\n]",equipeaux);
      k=0;

      while(k<campeonato[l].num_equs) {
	if(compara_cadeia(equipeaux,campeonato[l].equipe[k].nome)==1) {
	  campeonato[l].equipe[k].pontos+=campeonato[l].sistema_pt[j];
	  if(j==0){
	    campeonato[l].equipe[k].chegadas[0]++;
	  }
	  if(j==1){
	    campeonato[l].equipe[k].chegadas[1]++;
	  }
	  if(j==2){
	    campeonato[l].equipe[k].chegadas[2]++;
	  }
	  k=campeonato[l].num_equs;
	} else {
	  k++;
	}
      }

    }


  }

  /*Qualificação*/

  /*Matrix de classificação de pilotos e equipes*/
  for(i=0;i<campeonato[l].num_plts;i++){
    quali_plt[0][i]=i;
    quali_plt[1][i]=campeonato[l].piloto[i].pontos;
  }

  for(i=0;i<campeonato[l].num_plts;i++){
    q_pilotos[i].indice=i;
    q_pilotos[i].pontos=campeonato[l].piloto[i].pontos;
    q_pilotos[i].primeiro=campeonato[l].piloto[i].chegadas[0];
    q_pilotos[i].segundo=campeonato[l].piloto[i].chegadas[1];
    q_pilotos[i].terceiro=campeonato[l].piloto[i].chegadas[2];
    q_pilotos[i].nome=campeonato[l].piloto[i].nome;
  }

  printf("\n%s\n",q_pilotos[0].nome);

  for(i=0;i<campeonato[l].num_equs;i++){
    quali_equs[0][i]=i;
    quali_equs[1][i]=campeonato[l].equipe[i].pontos;
  }

  for(i=0;i<campeonato[l].num_equs;i++){
    q_equipe[i].indice=i;
    q_equipe[i].pontos=campeonato[l].equipe[i].pontos;
    q_equipe[i].primeiro=campeonato[l].equipe[i].chegadas[0];
    q_equipe[i].segundo=campeonato[l].equipe[i].chegadas[1];
    q_equipe[i].terceiro=campeonato[l].equipe[i].chegadas[2];
    q_equipe[i].nome=campeonato[l].equipe[i].nome;
  }

  printf("\n%s\n",q_equipe[0].nome);

  /*Ordenando pilotos e equipes*/
  quicksort(0,campeonato[l].num_plts-1,quali_plt);
  quicksort(0,campeonato[l].num_equs-1,quali_equs);

  printf("Classificação apos %d provas realizadas\n\n",q);

  printf("Pilotos\n\n");

  for(i=0;i<campeonato[l].num_plts;i++)
    printf("%2d. %s, %s, %d pontos\n",i+1,
campeonato[l].piloto[quali_plt[0][campeonato[l].num_plts-1-i]].nome,
campeonato[l].equipe[campeonato[l].piloto[quali_plt[0][campeonato[l].num_plts-1-i]].equipe].nome,
campeonato[l].piloto[quali_plt[0][campeonato[l].num_plts-1-i]].pontos);

  printf("\nEquipes\n\n");

  for(i=0;i<campeonato[l].num_equs;i++)
    printf("%2d. %s, %d pontos\n",i+1,
campeonato[l].equipe[quali_equs[0][campeonato[l].num_equs-1-i]].nome,
campeonato[l].equipe[quali_equs[0][campeonato[l].num_equs-1-i]].pontos);

  printf("\n\n");

  }

  return 0;
}
