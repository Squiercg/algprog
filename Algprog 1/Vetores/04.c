#include <stdio.h>

/*Um jogador viciado de cassino deseja fazer um levantamento estatístico simples sobre
uma roleta. Para isso, ele fez n lançamentos nesta roleta. Sabendo que uma roleta contém
37 números (de 0 a 36), calcular a freqüência de cada número desta roleta nos n lança-
mentos realizados.*/

int main(void)
{
  int i, n, entrada, roleta[37] = {0};

  printf("Entre com n: ");
  scanf("%d",&n);

  printf("Entre com os números que sairam na roleta:\n");

  for(i=1;i<=n;i++) {
    scanf("%d",&entrada);
    roleta[entrada]++;
  }

  for(i=0;i<=37;i++){
    if(roleta[i]>0){
      printf("O número %d saiu %d.\n",i,roleta[i]);
    }
  }

  printf("Fim :)\n");

  return 0;
}
