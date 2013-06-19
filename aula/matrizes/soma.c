#include <stdio.h>

int main(void)
{
  int a[100] = {0}, b[100] = {0}, soma[100] = {0};
  int cont1, cont2, i , carry;

  cont1=0;
   scanf("%d",&a[cont]);

  while(a[cont]!=-1) {
    cont++;
    scanf("%d", &a[cont]);
  }

  cont2=0;
  scanf("%d",&b[cont]);

  while(b[cont]!=-1) {
    cont++;
    scanf("%d", &b[cont]);
  }

  carry=0;

  if(cont1>cont2) {
    contmenor=cont2;
  } else {
    contmenor=cont1;
  }

  if(contmenor == cont2) {

    for(i=cont1 - 1 ; i<=(cont1-cont2) ; i--) {
      soma[i]=a[i]+b[i]+carry;
      carry = soma[i] / 10;
      soma[i] = soma[i] % 10;
  }

  for(i=0;i<cont;i++) {
    printf("%d",soma[i]); 
  }

  printf("\n");

  return 0;
}
