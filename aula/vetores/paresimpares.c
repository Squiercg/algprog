#include <stdio.h>

int main(void)
{
  int num[100], pares[50], impares[50] , par , imp , n, i;

  scanf("%d",&n);

  for(i=0;i<n;i++) {
    scanf("%d",&num[i]);
  }

  par=0;
  imp=0;

  for(i=0;i<n;i++) {
    if(num[i] % 2 == 0) {
      pares[par]=num[i];
      par++;
    } else {
      impares[imp]=num[i];
      imp++;
    }
  }

  printf("Par: %d\n",par);
  for(i=0;i<par;i++) {
    printf("%d\n",pares[i]);
  }

  printf("Impar: %d\n",imp);
  for(i=0;i<imp;i++) {
    printf("%d\n",impares[i]);
  }


  return 0;
}
