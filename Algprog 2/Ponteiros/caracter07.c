#include <stdio.h>

int nchar(char *cadeia){
  int cont=0;
  while(*cadeia!='\0') {
    cont++;
    cadeia++;
  }
  return cont;
}

int nvogal(char *cadeia) {
  int cont=0;
  while(*cadeia!='\0') {
    if(*cadeia=='a' ||
       *cadeia=='A' ||
       *cadeia=='e' ||
       *cadeia=='E' ||
       *cadeia=='i' ||
       *cadeia=='I' ||
       *cadeia=='o' ||
       *cadeia=='O' ||
       *cadeia=='u' ||
       *cadeia=='U') {
    cont++;
    }
    cadeia++;
  }
  return cont;
}

int nletras(char *cadeia){
  int cont=0;
  while(*cadeia!='\0') {
    if( (*cadeia>=97&&*cadeia<=122) || (*cadeia>=65&&*cadeia<=90)) {
    cont++;
    }
    cadeia++;
  }
  return cont;
}

int nespaco(char *cadeia){
  int cont=0;
  while(*cadeia!='\0') {
    if( *cadeia==' ') {
    cont++;
    }
    cadeia++;
  }
  return cont;
}


int nconsoante(char *cadeia){
  return nletras(cadeia)-nvogal(cadeia);
}

int npontua(char *cadeia) {
  return nchar(cadeia)-nletras(cadeia)-nespaco(cadeia);
}

int main(void) {
  int n,i;
  float mvol=0, mcon=0 , mpon=0;
  char frase[100];

  scanf("%d",&n);

  for(i=0;i<n;i++) {
    scanf("\n %[^\n]",&frase);
    mvol+=nvogal(&frase);
    mcon+=nconsoante(&frase);
    mpon+=npontua(&frase);
  }

  printf("Vogal:%f Consoante:%f Pontua:%f \n",mvol/n,mcon/n,npon/n);

  return 0;
}
