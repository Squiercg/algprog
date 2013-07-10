#include <stdio.h>

int main(void)
{
  struct {
    char nome[16];
    int setor;
    int qtdd;
    float pcompra;
    float pvenda;
  } produto[500];

  int n,i,cod;

  scanf("%d",&n);

  for(i=0;i<n;i++) {
    scanf("%s",produto[i].nome);
    scanf("%d",&produto[i].setor);
    scanf("%d",&produto[i].qtdd);
    scanf("%f",&produto[i].pcompra);
    scanf("%f",&produto[i].pvenda);
  }

  scanf("%d",&cod);
  while(cod>=1 && cod<=4){

    if(cod==1){
      printf("Inferior a 10: ");
      for(i=0;i<n;i++)
	if(produto[i].qtdd<10)
	  printf("%s ",produto[i].nome);
    }

    if(cod==2) {
      printf("Lucro baixo: ");
      for(i=0;i<n;i++)
	if((produto[i].pvenda-produto[i].pcompra)<produto[i].pcompra*0.1)
	  printf("%s ",produto[i].nome);
    }

   if(cod==3) {
      printf("Lucro alto: ");
      for(i=0;i<n;i++)
	if((produto[i].pvenda-produto[i].pcompra)>produto[i].pcompra*0.1)
	  printf("%s ",produto[i].nome);
   }

   if(cod==4) {
      printf("Produtos zerados: ");
      for(i=0;i<n;i++)
	if(produto[i].qtdd==0)
	  printf("%d ",produto[i].setor);
   }

   printf("\n");
   scanf("%d",&cod);
  }	 

  return 0;
}
