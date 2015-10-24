#include <stdio.h>
/*Aluno: Augusto Cesar de Aquino Ribas
Algoritmos de programação turma 03
Analise de sistemas.*/

/*Esse programa divide uma planilha inicial em duas tabelas, uma de vendas e outra de compras*/

typedef struct {
  char descricao[101], fornecedor[101];
  int codigo, prazo;
  float pcompra, pvenda;
  int prod, forn;
} registro;

/*Função para comparar se duas strings são iguais*/
int comparastring(char a[], char b[]) {
  int i=0, saida=1;

  while(a[i]!='\0' && b[i]!='\0') {
    if(a[i]!=b[i]) {
      saida=0;
    }
    i++;
  }

  return saida;
}

int main(void)
{
  registro tabela[100] = {{{0}}} ;
  int n, i, j ;

  /*Entrada de dados*/
  printf("Entre com o número de entradas: ");
  scanf("%d",&n);


  for(i=0;i<n;i++) {
    printf("Descrição: ");
    scanf(" %[^\n]",tabela[i].descricao);
    printf("Codigo: ");
    scanf("%d",&tabela[i].codigo);
    printf("Preço de compra: ");
    scanf("%f",&tabela[i].pcompra);
    printf("Fornecedor: ");
    scanf(" %[^\n]",tabela[i].fornecedor);
    printf("Prazo: ");
    scanf("%d",&tabela[i].prazo);
    printf("Preço de venda: ");
    scanf("%f",&tabela[i].pvenda);
    printf("\n");
  }

  /*Processamento e saida para tabela prod*/
  printf("\nTabela Prod:.\n");
  for(i=0;i<n;i++) {

    if(tabela[i].prod==0) {
      for(j=i;j<n;j++) {
	if(tabela[i].codigo==tabela[j].codigo) {
	  tabela[j].prod=1;
	}
      }

      printf("Código: %d\n",tabela[i].codigo);
      printf("Descrição: %s\n",tabela[i].descricao);
      printf("Preço de venda: %.2f\n",tabela[i].pvenda);
      printf("\n");

    }

  }

  /*Processamento e saida para tabela forn*/
  printf("\nTabela Forn:.\n");
  for(i=0;i<n;i++) {

    if(tabela[i].forn==0) {
      printf("Fornecedor: %s\n",tabela[i].fornecedor);

      for(j=i;j<n;j++) {
	if(comparastring(tabela[i].fornecedor,tabela[j].fornecedor)) {
	  tabela[j].forn=1;
	  printf("Código: %d\n",tabela[j].codigo);
	  printf("Preço de compra: %.2f\n",tabela[j].pcompra);
	  printf("Prazo: %d\n",tabela[j].prazo);
	}
      }

      printf("\n");
    }

  }

  return 0;
}
