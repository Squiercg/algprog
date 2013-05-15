#include <stdio.h>

int main(void)
{

  scanf("%d", &n);
  contador= 1;

  while(i<=n) {
    scanf("%d %d", &numerador , &denominador)
      
      if(numerador<denominador)
	divisor = numerador ;
      else
	divisor = denominador ;

    for(i=2 ; i<=divisor ; i++) {

      if(numerador % i == 0 && denominador % i == 0 )
	maxdiv=i;
    }
   
    printf("%d %d\n",numerador/maxdiv,denominador/maxdiv);


  }




  return 0;
}
