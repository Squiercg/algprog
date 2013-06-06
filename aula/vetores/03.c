#include <stdio.h>

/*Tentando descobrir se um dado era viciado, um dono de cassino o lançou n vezes. Dados
os n resultados dos lançamentos, determinar o número de ocorrências de cada face.*/

int main(void)
{
  int jogada,  i, n, dado[6] = {0} ;


  printf("Informe o número de lançamentos: ");
  scanf("%d", &n);

  for(i=1;i<=n;i++) {
    printf("Jogada %d: ",i);
    scanf("%d", &jogada);
    dado[jogada-1]++;
  }

  printf("Resultado: \n");

  for(i=1;i<=6;i++) {
    printf("%d caiu %d x, %.2f porcento\n",i,dado[i-1],dado[i-1]/6.0);
  }

  return 0;
}
