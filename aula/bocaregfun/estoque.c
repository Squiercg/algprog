#include <stdio.h>

typedef struct {
  char nome[101];
  int setor , quantidade;
  float pc, pv;
} produto;

int main(void)
{
  int n,i , menu;
  produto hypermercadinho[500];


  scanf("%d",&n);

  for(i=0;i<n;i++) {
    scanf(" %[^\n]",hypermercadinho[i].nome);
    scanf("%d",hypermercadinho[i].setor);
    scanf("%d",hypermercadinho[i].quantidade);
    scanf("%f",hypermercadinho[i].pc);
    scanf("%f",hypermercadinho[i].pv);
  }

  scanf("%d",menu);

  while(menu>=1 || menu<=4) {

    if(menu==1) {
      for(i=0;i<n;i++) {
	if(hypermercadinho[i].quantidade<10)
	  printf("%s ",hypermercadinho[i].nome);
      }
    }

    if(menu==2) {

    }

    if(menu==3) {

    }

    if(menu==4) {

    }


  scanf("%d",menu);
  }

  return 0;
}
