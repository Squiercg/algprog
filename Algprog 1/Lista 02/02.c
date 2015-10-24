#include <stdio.h>
/*Aluno: Augusto Cesar de Aquino Ribas
Algoritmos de programação turma 03
Analise de sistemas.*/

/*Esse programa recebe uma matriz quadrada e contabiliza a frequencia dos números de 0 a 10*/

int main(void)
{
  int i, j, n, matriz[100][100];
  float vetor[11];

  /*Entrada de dados*/
  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      scanf("%d",&matriz[i][j]);
    }
  }

  /*Processamento*/
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
    vetor[matriz[i][j]]++;
    }
  }

  /*Saida, em porcentagem ja que o exercicio pede frequencia e não contagem*/
  for(i=0;i<11;i++){
    printf("Número %d: %.2f\n", i , vetor[i]/ (n*n));
  }

  return 0;
}
