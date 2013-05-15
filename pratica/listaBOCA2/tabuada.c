#include <stdio.h>

int main(void)
{
  int i , j ;

  for(j=2 ; j<=10 ; j++ ) {

    for(i=0 ; i<=10 ; i++ ) {

      printf("%d x %d = %d\n", j , i , j * i) ;

    }
  }

  return 0;

}

