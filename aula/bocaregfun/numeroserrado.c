#include <stdio.h>


/*Essa função conta quantos digitos um número tem*/
int tamanho(int n) {
  int i=0;

  while(n>0) {
    n=n/10;
    i++;
  }

  return i;

}

/*Essa função retorna os k primeiros digitos de um número n*/
int kdigito(int n, int k) {
  int i, mod, aux ,saida;

  aux=1;
  saida=0;

  for(i=1;i<=k;i++) {
    mod = n%10;
    saida = saida + (mod*aux);
    aux=aux*10;
    n=n/10;
  }

  return saida;

}

int main(void)
{
  int i, n , a[100] , b[100] , resposta[100] ;

  /*Entrada de dado*/
  scanf("%d", &n);

  for(i=0;i<n;i++) {
    scanf("%d %d",&a[i],&b[i]);
  }

  /*Processamento*/
  for(i=0;i<n;i++) {

    if( b[i] == kdigito( a[i] , tamanho(b[i]) ) ) {
      resposta[i]=1;
    } else {
      resposta[i]=0;
    }

  }

  /*Saida*/
  for(i=0;i<n;i++) {
    if(resposta[i]==1) {
      printf("Encaixa\n");
    } else {
      printf("Nao encaixa\n");
    }
  }

  return 0;
}
