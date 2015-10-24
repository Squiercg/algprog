#include <stdio.h>
/*Aluno: Augusto Cesar de Aquino Ribas
Algoritmos de programação turma 03
Analise de sistemas.*/

/*Esse programa é o o sitema para um banco, ele registra contas, apos estas registradas é possivel sacar, depositar,
  tirar saldo e extrado*/

typedef struct{
  char nome[101];
  int conta , senha , cpf, op;
  float saldo[100];
} registro;

/*Essa função encontra o indice da conta desejada dentro das contas registradas*/
int achaconta(registro banco[], int conta , int cont) {
  int i, indice;

  for(i=0;i<cont;i++) {
    if(banco[i].conta==conta) {
      indice=i;
    } else {
      indice=-1;
    }
  }

  return indice;

}

int main(void)
{
  registro banco[100];
  int conta , senha , cont=0, opt, ind, i;
  float soma;

  printf("Entre com um número de conta: ");
  scanf("%d",&conta);
  printf("Digite a senha: ");
  scanf("%d",&senha);

  while((conta!=0) && (senha!=999)) {
    printf("Contas cadastradas: %d\n",cont);
    printf("Digite:\n");
    printf("01: Abrir conta\n");
    printf("02: Saque\n");
    printf("03: Deposito\n");
    printf("04: Saldo\n");
    printf("05: Extrato\n");
    printf("Entre com uma opção: ");
    scanf("%d",&opt);

    if(opt<1 || opt>5) {
      printf("Opção invalida.\n");
    }

    /*Abrindo uma conta*/
    if(opt==1) {
      banco[cont].conta=conta;
      banco[cont].senha=senha;
      printf("Entre com o nome do correntista:");
      scanf(" %[^\n]",banco[cont].nome);
      printf("Entre com o cpf do correntista:");
      scanf("%d",&banco[cont].cpf);
      banco[cont].op=0;
      banco[cont].saldo[0]=0;
      cont++;
    }

    /*Realizando um saque, aqui a senha é verificada para autorizar a transação*/
    if(opt==2) {
      ind=achaconta(banco,conta,cont);

      if(banco[ind].senha==senha) {
	soma=0;
	printf("Entre com o valor do saque: ");
	scanf("%f",&soma);
	banco[ind].saldo[banco[ind].op+1]=-1*soma;
	banco[ind].op++;
      } else {
	printf("Senha invalida\n");
      }
    }

    /*Deposito*/
    if(opt==3) {
      ind=achaconta(banco,conta,cont);
      printf("Entre com o valor do deposito: ");
      scanf("%f",&banco[ind].saldo[banco[ind].op+1]);
      banco[ind].op++;
    }

    /*Saldo*/
    if(opt==4) {
      ind=achaconta(banco,conta,cont);

      soma=0.0;
      for(i=1;i<=banco[ind].op;i++) {
	soma=soma+banco[ind].saldo[i];
      }
      printf("O saldo é %.2f\n",soma);

    }

    /*Extrato*/
    if(opt==5) {
      ind=achaconta(banco,conta,cont);

      soma=0.0;
      for(i=1;i<=banco[ind].op;i++) {
	if(banco[ind].saldo[i]>0) {
	  printf("Deposito %.2f\n",banco[ind].saldo[i]);
	} else {
	  printf("Saque %.2f\n",banco[ind].saldo[i]);
	}
	soma=soma+banco[ind].saldo[i];
      }
      printf("O saldo é %.2f\n",soma);

    }

  printf("\nEntre com um número de conta: ");
  scanf("%d",&conta);
  printf("Digite a senha: ");
  scanf("%d",&senha);
  }

  printf("\n");
  return 0;
}
