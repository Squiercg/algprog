#include <stdio.h>

int tamanho(char *cadeia) {
  int n=0;

  while(cadeia[n]!='\0') {
    n++;
  }

  return n;

}


void copia(char *original, char *copia) {
  int i=0;

  do{
    copia[i]=original[i];
    i++;
  }while(original[i-1]!='\0');

}


int main(void) {

  char palavra[21],maior[21],menor[21];

  do{
  printf("Informe uma palavra:");
  scanf("%s",palavra);

  if(tamanho(palavra)>tamanho(maior)){
     copia(palavra,maior);
  }

  if(tamanho(palavra)<tamanho(menor)){
     copia(palavra,menor);
  }

  }while(tamanho(palavra)!=4);


  printf("Maior palavra: %s\n",maior);
  printf("Menor palavra: %s\n",menor);

  return 0;
}
