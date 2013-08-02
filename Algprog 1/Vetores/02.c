#include <stdio.h>
#define Nq 5

/* Uma prova consta de 30 questões, cada uma com cinco alternativas identificadas
pelas letras A, B, C, D e E. Dado o cartão gabarito da prova e o cartão de respostas
de n estudantes, com 1 n 100, computar o número de acertos de cada um dos estudantes. */

int main(void)
{
  int i, j, n;
  char Gabarito[Nq], Prova[Nq];
  float nota;

  for(i=0;i<Nq;i++) {
    Gabarito[i] = 'c';
  }

  printf("Entre com o número de estudantes a serem avaliados: ");
  scanf("%d",&n);

  for(i=1;i<=n;i++) {

    printf("Entre com o gabarito do aluno %d da %d questões\n",i,Nq);

    for(j=0;j<Nq;j++) {
      scanf("%c", &Prova[j]);
    }

    nota=0;

    for(j=0;j<Nq;j++) {
      if(Gabarito[j]==Prova[j]) {
	  nota+=1;
      }
    }

    nota = ((float) nota / (float) Nq) * 10;
    printf("A nota do aluno %d é %.2f.\n",i,nota);

  }

  return 0;
  }
