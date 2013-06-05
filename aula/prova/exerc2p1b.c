#include <stdio.h>

int main(void)
{
  int mat , idade ;
  printf("Entre com a matricula: ");
  scanf("%d", &mat);

  while(mat != 0 ) {
    printf("Entre com a idade: ");
    scanf("%d" , &idade);

    if(idade<16) {
      printf("Não votante.\n");
	} else {
      if(idade>=18 && idade<=65) {
	printf("Eleitor obrigatório.\n");
      } else {
	printf("Eleitor facultativo.\n");
      }
    }
    printf("Entre com a matricula: ");
    scanf("%d",&mat);
  }

  return 0;
}
