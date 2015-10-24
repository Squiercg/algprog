#include <stdio.h>

void maiuscula(char cadeia[]){
  int i=0;

  while(cadeia[i]!='\0') {
    if(cadeia[i]>=97&&cadeia[i]<=123) {
      cadeia[i]=cadeia[i]-32;
    }
    i++;
  }
}

void maiusculap(char *cadeia) {

  while(*cadeia!='\0') {
    if(*cadeia>=97 && *cadeia<=123) {
      *cadeia=*cadeia-32;
    }
    cadeia++;
  }
}


int main(void) {

  char palavra[]="Augusto Ribas";

  printf("Original %s\n",palavra);

  maiusculap(palavra);

  printf("Alterado %s\n",palavra);

  return 0;
}
