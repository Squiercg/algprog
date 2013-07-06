#include <stdio.h>

typedef struct{
  char nome[101], conceito;
  int rga;
  float p1 , p2 , t1, media;

} registro;

int main(void)
{
  registro aluno[100], aux;
  int n , i , j;

  /*Entrada*/
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf(" %[^\n]",aluno[i].nome);
    scanf("%d",&aluno[i].rga);
    scanf("%f",&aluno[i].p1);
    scanf("%f",&aluno[i].p2);
    scanf("%f",&aluno[i].t1);
  }

  /*Processamwento*/

  /*Média*/
  for(i=0;i<n;i++){
    aluno[i].media = (((aluno[i].p1 + aluno[i].p2) / 2) * 0.75) + (aluno[i].t1 * 0.25);
  }

  /*Conceito*/

  for(i=0;i<n;i++){
    if(aluno[i].media<4.9) {
      aluno[i].conceito = 'D';
    } else {
      if(aluno[i].media<6.9) {
	aluno[i].conceito = 'C';
      } else {
	if(aluno[i].media<8.9) {
	  aluno[i].conceito = 'B';
	} else {
	  aluno[i].conceito = 'A';
	}
      }
    }
  }

  /*Organizando a lista com algoritimo da bolha*/
  for(i=n-2;i>=0;i--) {
    for(j=0;j<=i;j++) {
      if(aluno[j].media<aluno[j+1].media) {
	aux=aluno[j+1];
	aluno[j+1]=aluno[j];
	aluno[j]=aux;
      }
    }
  }

  /*Saida A(65) -> B(68)*/
  j=0;

  for(i=65;i<=68;i++){

    printf("Conceito %c\n",i);

    while(aluno[j].conceito == i) {
      printf("%d %.1f\n",aluno[j].rga,aluno[j].media);
      j++;
    }

  }

  return 0;
}
