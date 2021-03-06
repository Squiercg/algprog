#include <stdio.h>
#define MAX 100

int insere(int n, int v[MAX], int k, int y) {
  int i;

  for(i=n;i>=k;i--){
    v[i]=v[i-1];
  }

  v[k-1]=y;


  return n+1;

}

int insereR(int n, int v[MAX], int k, int x) {

  if(n==k) {
    v[n]=v[n-1];
    v[k-1]=x;
    return n+1;
  } else {
    v[n]=v[n-1];
    return 1+insereR(n-1,v,k,x);
  }




}

int main(void)
{
  int n1, n2, i, vetor1[MAX+1] , vetor2[MAX+1] , k , y;

  scanf("%d",&n1);

  for(i=0;i<n1;i++) {
    scanf("%d",&vetor1[i]);
  }

  scanf("%d",&k);

  scanf("%d",&y);

  n2=n1;

  for(i=0;i<n1;i++) {
    vetor2[i]=vetor1[i];
  }

  n1=insere(n1,vetor1,k,y);

  for(i=0;i<n1;i++) {
    printf("%d ",vetor1[i]);
  }
  printf("\n");

  n2=insereR(n2,vetor2,k,y);

  for(i=0;i<n2;i++) {
    printf("%d ",vetor2[i]);
  }
  printf("\n");


  return 0;
}
