#include <stdio.h>

int main(void)
{
  int a[100] = {0}, b[100] = {0}, soma[100] = {0};
  int cont, i;

  cont=0;
   scanf("%d",&a[cont]);

  while(a[cont]!=-1) {
    cont++;
    scanf("%d", &a[cont]);
  }

  cont=0;
  scanf("%d",&b[cont]);

  while(b[cont]!=-1) {
    cont++;
    scanf("%d", &b[cont]);
  }



  for(i=0;i<cont;i++) {
    soma[i]=a[i]+b[i];
  }



  for(i=0;i<cont;i++) {
    printf("%d",soma[i]); 
  }

  printf("\n");

  return 0;
}