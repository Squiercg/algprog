#include <stdio.h>


/*Essa função conta quantos digitos um string tem*/
int tamanho(char string[]) {
  int cont=0;

  while(string[cont]!='\0') {
    cont++;
  }

  return cont;
}

/*Compara compara string*/
int compstring(char s1[], char s2[], int m , int n) {
  int saida=0;

  while( (s1[m-1]==s2[n-1]) && (n>0) ) {

    if(n==1) {
      saida=1;
    }

    m--;
    n--;

  }


  return saida;

}


int main(void)
{
  int i, n ;
  char a[100] , b[100];

  /*Entrada de dado*/
  scanf("%d", &n);

  for(i=0;i<n;i++) {
    scanf("%s", a);
    scanf("%s", b);

    if( compstring(a,b,tamanho(a),tamanho(b))==1 ) {
      printf("Encaixa\n");
    } else {
      printf("Nao encaixa\n");
    }
  }

  return 0;
}
