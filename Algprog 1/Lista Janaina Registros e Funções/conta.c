#include <stdio.h>

int main(void)
{
  int n , e, i , cont ,vetor[100];

  scanf("%d %d", &n , &e);

  for(i=0;i<n;i++) {
    scanf("%d",&vetor[i]);
  }

  cont=0;

  for(i=0;i<n;i++) {
    if(vetor[i]==e){
      cont++;
    }
  }

  printf("%d\n",cont);


  return 0;
}
