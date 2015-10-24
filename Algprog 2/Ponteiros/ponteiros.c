#include <stdio.h>
#include <stdlib.h>

void minmax(int v[], int n, int *max, int *min) {
  int i;
  *max=v[0];
  *min=v[0];

  for(i=1;i<n;i++) {
    if(*max<v[i]) {
      *max=v[i];
    }
    if(*min>v[i]) {
      *min=v[i];
    }
  }

}


void doisMaiores(int v[], int n, int *p_maior, int *s_maior){
  int i;
  *p_maior=v[0];
  *s_maior=v[0];

  for(i=1;i<n;i++) {
    if(*s_maior<v[i]) {
      if(*p_maior<v[i]) {
	*s_maior=*p_maior;
	*p_maior=v[i];
      } else {
	*s_maior=v[i];
      }
    }
  }

}

void somaprod(int a, int b, int *soma, int *prod) {
 
  *soma=a+b;
  *prod=a*b;

}


int *maximo(int v[], int n) {
  int i, *aux;

  aux=&v[0];

  for(i=1;i<n;i++) {
    if(*aux<v[i])
      aux=&v[i];
  }

  return aux;

}



int main(void)
{
  int i, n , vetor[100], min , max , p_maior, s_maior, soma , prod , *pmaximo;
  scanf("%d",&n);

  for(i=0;i<n;i++){
    vetor[i]=rand()%50;
  }

  for(i=0;i<n;i++){
    printf("%d ",vetor[i]);
  }
  printf("\n");

  minmax(vetor,n,&max,&min);

  printf("Maior: %d Menor:%d \n",max,min);

  doisMaiores(vetor,n,&p_maior,&s_maior);

  printf("Primeiro: %d Segundo:%d \n",p_maior,s_maior);

  somaprod(vetor[0],vetor[1],&soma,&prod);

  printf("Soma: %d Produto:%d \n",soma,prod);

  pmaximo=maximo(vetor,n);

  printf("Pondeiro: %p com endereço:%p aponta para:%d \n",(void*)&pmaximo,(void*)pmaximo,*pmaximo);

  return 0;
}
