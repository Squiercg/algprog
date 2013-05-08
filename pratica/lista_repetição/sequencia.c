#include <stdio.h>

int main(void)
{

  int m, n, i , j , x , y, teste;

  scanf("%d %d", &n , &m );


  for(j=1 ; j<=n ; j++ ) {
    x=0;
    y=0;
    i=1;
    teste=0;

    do {

      scanf("%d" , &x );

      if(x < y) {
	teste = 1;
      }

      y = x;

      i++;

    } while(i<=m);

    if(teste)
    printf("baguncado\n");
    else
    printf("ordenado\n");

  }

    return 0;

}
